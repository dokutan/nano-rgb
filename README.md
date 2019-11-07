# nano-rgb
2-channel Arduino Nano RGB strip controller

# Parts

- 1 Arduino Nano
- 4 Pushbuttons (optional)
- per channel:
  - 3 220Ω Resistors (this value doesn't really matter)
  - 3 BS170 MOSFETs
  - Screw terminals or pin headers (optional)
  - pin headers and jumper to power the Arduino from the LED power supply (optional)
  
  **Warning:** don't exceed the current limits of the MOSFET, and if you are trying to supply the Arduino from the power supply instead of USB, make sure the it can handle the voltage.
