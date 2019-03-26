FROM devkitpro/devkita64

RUN dkp-pacman -Syyu --noconfirm devkitARM && \
    dkp-pacman -Syyu --noconfirm devkitarm-rules && \
    dkp-pacman -Scc --noconfirm && \
    git clone --recurse-submodules  https://github.com/switchbrew/libnx && cd libnx && \
    make -j8 && make install

RUN apt update && apt install -y python3 python3-pip zip && \
    pip3 install pycrypto pycryptoplus && \
    ln -s /usr/bin/python3 /usr/bin/python

ENV DEVKITARM=${DEVKITPRO}/devkitARM

WORKDIR /developer

ENTRYPOINT ["sh","entrypoint.sh"]
