FROM alpine:3.10

RUN \
    apk update; \
    apk add --no-cache --virtual .build-deps \
        --repository http://dl-cdn.alpinelinux.org/alpine/edge/main \
        --repository http://dl-cdn.alpinelinux.org/alpine/edge/community \
        --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing \    
        git \
        cmake \
        make \
        g++ \
        gcc \
        build-base \
        linux-headers \
        bzip2-dev \
        musl-dev \
        gdal-dev=3.1.0-r2 \
        geos-dev \
        proj-dev \
        libgeotiff-dev \
        python-dev \
        boost-dev \
        poppler \
        alpine-sdk

ADD . /usr/local/src/tin-terrain/
RUN mkdir /var/tmp/tin-terrain-build/
WORKDIR /var/tmp/tin-terrain-build/
RUN cmake -DCMAKE_BUILD_TYPE=Debug /usr/local/src/tin-terrain/

RUN VERBOSE=1 make -j`nproc`
RUN cp ./tin-terrain /usr/local/bin/
RUN rm -rf /var/tmp/tin-terrain-build/
RUN ls /usr/local/bin
WORKDIR /home
