git clone https://github.com/switchbrew/libnx
cd libnx
make
make install
wget https://ave.zone/sept-secondary.enc -O /tmp/sept-secondary.enc
make all
cp /tmp/sept-secondary.enc sept/sept-secondary/sept-secondary.enc
make dist
