git clone https://github.com/switchbrew/libnx
cd libnx
make
make install
cd ..
make all
make dist
wget https://ave.zone/sept-secondary.enc -O /tmp/sept-secondary.enc
cp /tmp/sept-secondary.enc out/
