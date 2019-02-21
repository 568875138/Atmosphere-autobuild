FROM devkitpro/devkita64
MAINTAINER elelphatp "elephantp@elephantp.blog"

RUN mkdir ${DEVKITPRO}/devkitARM && \
    wget https://github.com/devkitPro/buildscripts/releases/download/devkitARM_r50/devkitARM_r50-linux.tar.xz && \
    tar xvJf devkitARM_r50-linux.tar.xz -C ${DEVKITPRO} && \
    git clone --recurse-submodules  https://github.com/switchbrew/libnx && cd libnx && \
    make -j8 && make install

RUN apt update && apt install -y python3 python3-pip zip && \
    pip3 install pycrypto pycryptoplus

ENV DEVKITARM=${DEVKITPRO}/devkitARM

WORKDIR /developer

ENTRYPOINT ["sh","entrypoint.sh"]
