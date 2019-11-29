# uleds-bridge
This program adds the nano-rgb to the Linux led subsystem.
It monitors the files in /sys/class/leds/ and wites the changes over serial to the Arduino.

## Installation

- Install:
``
sudo make install
``
- Uninstall:
``
sudo make uninstall
``


## Usage
- The uleds kernel module is required. Load it with
``
sudo modprobe uleds
``
- Check if it is loaded with 
``
lsmod | grep uleds
``
- Run the program (replace <arduino> with the correct path, for example /dev/ttyUSB0)
``
sudo uleds-bridge -a <arduino>
``
- The leds should show up in /sys/class/leds

## TODO
- [x] Add second channel support to bridge and arduino code
- [x] Parse options:
  - [x] Arduino
  - [ ] Optionally daemonize ?
- [ ] Add support for more than one physical device
- [ ] Write makefile
