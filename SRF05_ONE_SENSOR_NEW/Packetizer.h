
#ifndef Packetizer_h
#define Packetizer_h

#include <Arduino.h>

class Packetizer
{
public:
  Packetizer(byte addr);
  byte *packetize(int value);
  byte SIZE;

private:
  byte _addr;
  byte message[3];
};

#endif
