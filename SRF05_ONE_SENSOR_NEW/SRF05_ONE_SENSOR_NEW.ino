#include <HCSR04.h>
#include "Packetizer.h"

#define NR_OF_SAMPLES 16
#define TRIG_PIN      5
#define ECHO_PIN_1    6

HCSR04      hc(TRIG_PIN, ECHO_PIN_1); // first argument is trig pin, second is the echo
Packetizer  pack1(0);                 // arg: address of the sensor (0-127), use it to labeling sensors, 0 is the first, 1 is the second, and so...

int         values[NR_OF_SAMPLES] = { 0 };
byte        count  = 0;
int         prev = 0;
int         max_value = 0;
int         min_value = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  //values[count] = hc.dist();
  
  Serial.println((int)hc.dist());
  
  delay(25);
  
}
