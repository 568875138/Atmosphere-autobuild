git clone https://github.com/switchbrew/libnx
cd libnx
make
make install
cd ..
make all
wget https://ave.zone/sept-secondary.enc -O /tmp/sept-secondary.enc
\cp -rf /tmp/sept-secondary.enc sept/sept-secondary/
make dist
