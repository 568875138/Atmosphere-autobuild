git clone https://github.com/switchbrew/libnx
cd libnx
make
make install
wget https://ave.zone/sept-secondary.enc -O /tmp/sept-secondary.enc
make all
make dist
cp /tmp/sept-secondary.enc out/
