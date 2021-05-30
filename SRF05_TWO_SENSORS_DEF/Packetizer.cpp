#include "Packetizer.h"

#define DEBUG 0

Packetizer::Packetizer(byte addr)
{
  this->message[0] = 128;
  this->message[1] = 128;
  this->message[2] = addr;
  this->SIZE = 3;
}

byte *Packetizer::packetize(int value)
{
  this->message[0] = ((value & 16256) >> 7) + 128;
  this->message[1] = (value & 127) + 128;
  #if DEBUG
  Serial.print("0: ");
  Serial.println(this->message[0]);
  Serial.print("1: ");
  Serial.println(this->message[1]);
  Serial.print("addr: ");
  Serial.println(this->message[2]);
  Serial.println();
  #endif
  return this->message;
}
