#include <HCSR04.h>

HCSR04 hc(2, new int[2]{5,6}, 2};
byte target1[] = { 128, 128, 0 };
byte target2[] = { 128, 128, 1 };

void setup() {
  Serial.begin(9600);
}

void loop() {
  int values[] = {0, 0};
  for (int i = 0; i<2; i++) {
    values[i] = hc.dist(i); 
  }

  packetize(target1, values[0], 0);
  packetize(target2, values[0], 1);

  Serial.write(target1, 3);
  Serial.write(target2, 3);
  
}

void packetize(byte *packet, int value, byte addr) {
  packet[0] = ((value & 16256) >> 7) + 128;
  packet[1] = (value & 127) + 128;
  packet[2] = addr;
}
