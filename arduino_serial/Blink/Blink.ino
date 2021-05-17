

byte values[] = { 128, 128, 0 };

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  for (int i=0; i<256; i=i+2) {
    packetize(values, i, 0);
    Serial.write(values, 3);
    delay(50);
  }
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW);
  for (int i=0; i<256; i=i+2) {
    packetize(values, i, 1);
    Serial.write(values, 3);
    delay(50);
  }
  delay(1000);
}

void packetize(byte *packet, int value, byte addr) {
  packet[0] = ((value & 16256) >> 7) + 128;
  packet[1] = (value & 127) + 128;
  packet[2] = addr;
}
