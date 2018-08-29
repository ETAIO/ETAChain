FROM ETAio/builder
ARG branch=master
ARG symbol=SYS

RUN git clone -b $branch https://github.com/ETAIO/ETA.git --recursive \
    && cd ETA && echo "$branch:$(git rev-parse HEAD)" > /etc/ETAio-version \
    && cmake -H. -B"/opt/ETAio" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_ROOT=/opt/wasm -DCMAKE_CXX_COMPILER=clang++ \
       -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/opt/ETAio  -DSecp256k1_ROOT_DIR=/usr/local -DBUILD_MONGO_DB_PLUGIN=true -DCORE_SYMBOL_NAME=$symbol \
    && cmake --build /opt/ETAio --target install \
    && cp /ETA/Docker/config.ini / && ln -s /opt/ETAio/contracts /contracts && cp /ETA/Docker/nodETAd.sh /opt/ETAio/bin/nodETAd.sh && ln -s /ETA/tutorials /tutorials

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates vim psmisc python3-pip && rm -rf /var/lib/apt/lists/*
RUN pip3 install numpy
ENV ETAIO_ROOT=/opt/ETAio
RUN chmod +x /opt/ETAio/bin/nodETAd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
VOLUME /opt/ETAio/bin/data-dir
ENV PATH /opt/ETAio/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
