#include "Packetizer.h"

Packetizer::Packetizer(byte addr)
{
  this->message[0] = 128;
  this->message[1] = 128;
  this->message[2] = _addr;
  this->SIZE = 3;
}

byte *Packetizer::packetize(int value)
{
  this->message[0] = ((value & 16256) >> 7) + 128;
  this->message[1] = (value & 127) + 128;
  return this->message;
}