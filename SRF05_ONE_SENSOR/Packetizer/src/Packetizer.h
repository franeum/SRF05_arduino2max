
#ifndef Packetizer_h
#define Packetizer_h

#include <Arduino.h>

class Packetizer 
{
  
  public:
    Packetizer(byte addr);
    void packetize(int value);
    byte * get_pack();

  private:
    byte *message;
};

#endif Packetizer_h
