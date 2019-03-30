# Exit on non-0 exit codes
set -e

curl https://gitlab.com/ao/BuildServNX/raw/master/build_scripts/meta/libnx-master.sh | bash

SHORT_GIT=$(echo $GIT_COMMIT | cut -c 1-7)

# This is based on the Makefile inside atmosphere repo, the dist part
# However it also includes kips, exosphere and documentation

MAJORVER=$(grep '\ATMOSPHERE_RELEASE_VERSION_MAJOR\b' common/include/atmosphere/version.h | tr -s [:blank:] | cut -d' ' -f3)
MINORVER=$(grep '\ATMOSPHERE_RELEASE_VERSION_MINOR\b' common/include/atmosphere/version.h | tr -s [:blank:] | cut -d' ' -f3)
MICROVER=$(grep '\ATMOSPHERE_RELEASE_VERSION_MICRO\b' common/include/atmosphere/version.h | tr -s [:blank:] | cut -d' ' -f3)
AMSVER="$MAJORVER.$MINORVER.$MICROVER"

# HACKY :3
echo $AMSVER > bsnx/vername.txt

# Latest encrypted sept from AMS
wget https://ave.zone/sept-secondary.enc -O /tmp/sept-secondary.enc

SEPT_ENC_PATH="/tmp/sept-secondary.enc" make all

mkdir -p bsnx/sd/atmosphere/titles/0100000000000036
mkdir -p bsnx/sd/atmosphere/titles/0100000000000034
mkdir -p bsnx/sd/atmosphere/titles/010000000000000D
mkdir -p bsnx/sd/atmosphere/titles/0100000000000032/flags
mkdir -p bsnx/sd/sept
mkdir -p bsnx/sd/switch
cp fusee/fusee-primary/fusee-primary.bin bsnx/fusee-primary-payload.bin
cp fusee/fusee-primary/fusee-primary.bin bsnx/sd/atmosphere/reboot_payload.bin
cp fusee/fusee-secondary/fusee-secondary.bin bsnx/sd/atmosphere/fusee-secondary.bin
cp fusee/fusee-secondary/fusee-secondary.bin bsnx/sd/sept/payload.bin
cp fusee/fusee-primary/fusee-primary.bin bsnx/sd/atmosphere/reboot_payload.bin

cp sept/sept-primary/sept-primary.bin bsnx/sd/sept/sept-primary.bin

# I don't have enough clout to have the right keys, so these will just be the latest sept files from latest release
cp /tmp/sept-secondary.enc bsnx/sd/sept/sept-secondary.enc

cp common/defaults/BCT.ini bsnx/sd/atmosphere/BCT.ini
cp common/defaults/loader.ini bsnx/sd/atmosphere/loader.ini
cp common/defaults/system_settings.ini bsnx/sd/atmosphere/system_settings.ini

cp -r common/defaults/kip_patches bsnx/sd/atmosphere/kip_patches
cp stratosphere/creport/creport.nsp bsnx/sd/atmosphere/titles/0100000000000036/exefs.nsp
cp stratosphere/fatal/fatal.nsp bsnx/sd/atmosphere/titles/0100000000000034/exefs.nsp
cp stratosphere/eclct.stub/eclct.stub.nsp bsnx/sd/atmosphere/titles/0100000000000032/exefs.nsp
cp stratosphere/dmnt/dmnt.nsp bsnx/sd/atmosphere/titles/010000000000000D/exefs.nsp

cp troposphere/reboot_to_payload/reboot_to_payload.nro bsnx/sd/switch/reboot_to_payload.nro

touch bsnx/sd/atmosphere/titles/0100000000000032/flags/boot2.flag

mkdir -p bsnx/kips/
cp stratosphere/sm/*.kip bsnx/kips/
cp stratosphere/pm/*.kip bsnx/kips/
cp stratosphere/ams_mitm/*.kip bsnx/kips/
cp stratosphere/loader/*.kip bsnx/kips/
cp exosphere/*.bin bsnx/kips/  # okay, this isn't a kip but still, I can't think of a better folder for this 

cp -r docs/ bsnx/docs/
