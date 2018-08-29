FROM ETAio/builder as builder
ARG branch=master
ARG symbol=SYS

RUN git clone -b $branch https://github.com/ETAIO/ETA.git --recursive \
    && cd ETA && echo "$branch:$(git rev-parse HEAD)" > /etc/ETAio-version \
    && cmake -H. -B"/tmp/build" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_ROOT=/opt/wasm -DCMAKE_CXX_COMPILER=clang++ \
       -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/tmp/build  -DSecp256k1_ROOT_DIR=/usr/local -DBUILD_MONGO_DB_PLUGIN=true -DCORE_SYMBOL_NAME=$symbol \
    && cmake --build /tmp/build --target install && rm /tmp/build/bin/ETAiocpp


FROM ubuntu:18.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates && rm -rf /var/lib/apt/lists/*
COPY --from=builder /usr/local/lib/* /usr/local/lib/
COPY --from=builder /tmp/build/bin /opt/ETAio/bin
COPY --from=builder /tmp/build/contracts /contracts
COPY --from=builder /ETA/Docker/config.ini /
COPY --from=builder /etc/ETAio-version /etc
COPY --from=builder /ETA/Docker/nodETAd.sh /opt/ETAio/bin/nodETAd.sh
ENV ETAIO_ROOT=/opt/ETAio
RUN chmod +x /opt/ETAio/bin/nodETAd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
VOLUME /opt/ETAio/bin/data-dir
ENV PATH /opt/ETAio/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
