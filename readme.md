# Quantum Mechanical Keyboard Firmware

## This is an outdated version of QMK firmware which supports Leeku L3 PCBs (Finger 60, 65, TKL) only!
Requires chibios, chibios-contrib, googletest, and ugfx folders in qmk_firmware-leeku/lib (they can be empty). 

Repo must be cloned into a Windows directory (e.g., /mnt/c/) when using WSL

## How to build

```
git clone https://github.com/nug-/qmk_firmware-leeku.git
git remote set-url origin git@github.com:nug-/qmk_firmware-leeku.git
cd qmk_firmware-leeku
git submodule init
git submodule update
make git-submodule
mkdir -p ./lib/chibios
mkdir -p ./lib/chibios-contrib
mkdir -p ./lib/googletest
mkdir -p ./lib/ugfx
make l3_finger65:nug
```
There may be some errors after running `make l3_finger65:nug` but the hex seems to compile okay.
