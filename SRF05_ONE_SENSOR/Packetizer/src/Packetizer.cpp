#include "Packetizer.h"

Packetizer::Packetizer(byte addr) {
  message[0] = 128;
  message[1] = 128;
  message[2] = addr; 
}

void Packetizer::packetize(int value) {
  message[0] = ((value & 16256) >> 7) + 128;
  message[1] = (value & 127) + 128;
}

byte * Packetizer::get_pack() {
  return message;  
}
