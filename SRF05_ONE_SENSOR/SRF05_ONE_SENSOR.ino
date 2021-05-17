#include <HCSR04.h>
#include <Packetizer.h>

HCSR04 hc(5,6); // first argument is trig pin, second is the echo
Packetizer pack1(0); // arg: address of hte sensor (0-127), use it to labeling sensors

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = hc.dist();

  // pack1.packetize(value) return a byte pointer
  Serial.write(pack1.packetize(value), pack1.SIZE);  

  delay(100);
  
}

/*
void packetize(byte *packet, int value, byte addr) {
  packet[0] = ((value & 16256) >> 7) + 128;
  packet[1] = (value & 127) + 128;
  packet[2] = addr;
}
*/
