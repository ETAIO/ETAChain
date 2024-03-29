# Run in docker

Simple and fast setup of ETA.IO on Docker is also available.

## Install Dependencies

- [Docker](https://docs.docker.com) Docker 17.05 or higher is required
- [docker-compose](https://docs.docker.com/compose/) version >= 1.10.0

## Docker Requirement

- At least 7GB RAM (Docker -> Preferences -> Advanced -> Memory -> 7GB or above)
- If the build below fails, make sure you've adjusted Docker Memory settings and try again.

## Build ETA image

```bash
git clone https://github.com/ETAIO/ETA.git --recursive  --depth 1
cd ETA/Docker
docker build . -t ETAio/ETA
```

The above will build off the most recent commit to the master branch by default. If you would like to target a specific branch/tag, you may use a build argument. For example, if you wished to generate a docker image based off of the v1.2.3 tag, you could do the following:

```bash
docker build -t ETAio/ETA:v1.2.3 --build-arg branch=v1.2.3 .
```

By default, the symbol in ETAio.system is set to SYS. You can override this using the symbol argument while building the docker image.

```bash
docker build -t ETAio/ETA --build-arg symbol=<symbol> .
```

## Start nodETA docker container only

```bash
docker run --name nodETA -p 8888:8888 -p 9876:9876 -t ETAio/ETA nodETAd.sh -e --http-alias=nodETA:8888 --http-alias=127.0.0.1:8888 --http-alias=localhost:8888 arg1 arg2
```

By default, all data is persisted in a docker volume. It can be deleted if the data is outdated or corrupted:

```bash
$ docker inspect --format '{{ range .Mounts }}{{ .Name }} {{ end }}' nodETA
fdc265730a4f697346fa8b078c176e315b959e79365fc9cbd11f090ea0cb5cbc
$ docker volume rm fdc265730a4f697346fa8b078c176e315b959e79365fc9cbd11f090ea0cb5cbc
```

Alternately, you can directly mount host directory into the container

```bash
docker run --name nodETA -v /path-to-data-dir:/opt/ETAio/bin/data-dir -p 8888:8888 -p 9876:9876 -t ETAio/ETA nodETAd.sh -e --http-alias=nodETA:8888 --http-alias=127.0.0.1:8888 --http-alias=localhost:8888 arg1 arg2
```

## Get chain info

```bash
curl http://127.0.0.1:8888/v1/chain/get_info
```

## Start both nodETA and kETAd containers

```bash
docker volume create --name=nodETA-data-volume
docker volume create --name=kETAd-data-volume
docker-compose up -d
```

After `docker-compose up -d`, two services named `nodETAd` and `kETAd` will be started. nodETA service would expose ports 8888 and 9876 to the host. kETAd service does not expose any port to the host, it is only accessible to clETA when running clETA is running inside the kETAd container as described in "Execute clETA commands" section.

### Execute clETA commands

You can run the `clETA` commands via a bash alias.

```bash
alias clETA='docker-compose exec kETAd /opt/ETAio/bin/clETA -u http://nodETAd:8888 --wallet-url http://localhost:8900'
clETA get info
clETA get account inita
```

Upload sample exchange contract

```bash
clETA set contract exchange contracts/exchange/
```

If you don't need kETAd afterwards, you can stop the kETAd service using

```bash
docker-compose stop kETAd
```

### Develop/Build custom contracts

Due to the fact that the ETAio/ETA image does not contain the required dependencies for contract development (this is by design, to keep the image size small), you will need to utilize the ETAio/ETA-dev image. This image contains both the required binaries and dependencies to build contracts using ETAiocpp.

You can either use the image available on [Docker Hub](https://hub.docker.com/r/ETAio/ETA-dev/) or navigate into the dev folder and build the image manually.

```bash
cd dev
docker build -t ETAio/ETA-dev .
```

### Change default configuration

You can use docker compose override file to change the default configurations. For example, create an alternate config file `config2.ini` and a `docker-compose.override.yml` with the following content.

```yaml
version: "2"

services:
  nodETA:
    volumes:
      - nodETA-data-volume:/opt/ETAio/bin/data-dir
      - ./config2.ini:/opt/ETAio/bin/data-dir/config.ini
```

Then restart your docker containers as follows:

```bash
docker-compose down
docker-compose up
```

### Clear data-dir

The data volume created by docker-compose can be deleted as follows:

```bash
docker volume rm nodETA-data-volume
docker volume rm kETAd-data-volume
```

### Docker Hub

Docker Hub image available from [docker hub](https://hub.docker.com/r/ETAio/ETA/).
Create a new `docker-compose.yaml` file with the content below

```bash
version: "3"

services:
  nodETAd:
    image: ETAio/ETA:latest
    command: /opt/ETAio/bin/nodETAd.sh --data-dir /opt/ETAio/bin/data-dir -e --http-alias=nodETAd:8888 --http-alias=127.0.0.1:8888 --http-alias=localhost:8888
    hostname: nodETAd
    ports:
      - 8888:8888
      - 9876:9876
    expose:
      - "8888"
    volumes:
      - nodETA-data-volume:/opt/ETAio/bin/data-dir

  kETAd:
    image: ETAio/ETA:latest
    command: /opt/ETAio/bin/kETAd --wallet-dir /opt/ETAio/bin/data-dir --http-server-address=127.0.0.1:8900 --http-alias=localhost:8900 --http-alias=kETAd:8900
    hostname: kETAd
    links:
      - nodETAd
    volumes:
      - kETAd-data-volume:/opt/ETAio/bin/data-dir

volumes:
  nodETA-data-volume:
  kETAd-data-volume:

```

*NOTE:* the default version is the latest, you can change it to what you want

run `docker pull ETAio/ETA:latest`

run `docker-compose up`

### ETAIO Testnet

We can easily set up a ETAIO local testnet using docker images. Just run the following commands:

Note: if you want to use the mongo db plugin, you have to enable it in your `data-dir/config.ini` first.

```
# create volume
docker volume create --name=nodETA-data-volume
docker volume create --name=kETAd-data-volume
# pull images and start containers
docker-compose -f docker-compose-ETAio-latest.yaml up -d
# get chain info
curl http://127.0.0.1:8888/v1/chain/get_info
# get logs
docker-compose logs -f nodETAd
# stop containers
docker-compose -f docker-compose-ETAio-latest.yaml down
```

The `blocks` data are stored under `--data-dir` by default, and the wallet files are stored under `--wallet-dir` by default, of course you can change these as you want.

### About MongoDB Plugin

Currently, the mongodb plugin is disabled in `config.ini` by default, you have to change it manually in `config.ini` or you can mount a `config.ini` file to `/opt/ETAio/bin/data-dir/config.ini` in the docker-compose file.
