# MCP3008_SPI - An ARDUINO library MCP3008 using native SPI


MCP3008 is a 10 bits, 8 channels ADC that can be controlled from an Arduino using SPI.

Adapted from https://github.com/nodesign/MCP3008

## Connections

Arduino | MCP3008
------- | -------
MOSI    | D<sub>in</sub>
MISO    | D<sub>out</sub>
SCK     | CLK
any digital | CS
5/3.3V  | V<sub>dd</sub>
5/3.3V   | V<sub>ref</ref>
GND  | AGND/DGND

Note that for best perfomances, digital and analog grounding (DGND and AGND) should be connected to digital and analogic parts of your circuit and be linked at only one point.
