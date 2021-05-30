
// library for HCSR04 is "HCSR04 ultrasonic sensor"
// u can download it from library manager

#include "HCSR04.h"
#include "Packetizer.h"

#define NR_OF_SENSORS 2
#define TRIG_PIN      5
#define SENSOR1       6
#define SENSOR2       12
#define DELAY_TIME    50

// 5 is (common) trig pin, 6 and 12 are echo pins for 2 sensors
HCSR04      hc(TRIG_PIN, new int[2]{ SENSOR1, SENSOR2 }, NR_OF_SENSORS);
Packetizer  *pack[NR_OF_SENSORS];

void setup() {
  Serial.begin(115200);

  for (int i=0; i<NR_OF_SENSORS; i++)
    pack[i] = new Packetizer(i);
}

void loop() {
  for (int i=0; i<NR_OF_SENSORS; i++) 
    Serial.write(pack[i]->packetize(hc.dist(i)), pack[i]->SIZE);

  delay(DELAY_TIME);
  
}
