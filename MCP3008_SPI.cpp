/*
  MCP3008_SPI.h library to communicate with MCP3008 8 channel adc using native SPI protocol.

  Adapted from Uros Petrevski, Nodesign.net 2013 by Thomas Combriat, 2019
  Public domain.
  ported from Python code originaly written by Adafruit learning system for rPI 
*/

#include "MCP3008_SPI.h"

MCP3008_SPI::MCP3008_SPI(int cspin)
{
  _cspin = cspin;
  pinMode(_cspin, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
}


int MCP3008_SPI::readADC(byte channel)
{
  digitalWrite(_cspin, LOW);
  byte commandout = channel;
  commandout |= 0x18; //  # start bit + single-ended bit
  commandout <<= 3; // # we only need to send 5 bits here
  byte result1 = SPI.transfer(commandout);
  int result2 = SPI.transfer16(0x00);
  digitalWrite(_cspin, HIGH);
  return result2 >>6; 
}
