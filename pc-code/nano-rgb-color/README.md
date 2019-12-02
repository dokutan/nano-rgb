# nano-rgb-color
This program allows directly setting the color over serial.

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
- The Arduino needs to be programmed with arduino-code/serial-in
- Run the program (replace arduino with the correct path, for example /dev/ttyUSB0). Example:
``
sudo nano-rgb-color -a arduino -1 ffff00
``

## TODO
- [ ] don't reset arduino when opening
