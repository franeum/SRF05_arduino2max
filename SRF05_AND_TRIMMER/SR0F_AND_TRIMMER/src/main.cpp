#include <Arduino.h>
#include <HCSR04.h>

#define MAX_DIST 534 // cm
#define DEF_THRESH 50 // cm
#define DEBOUNCE 200 // msecs
#define DEBUG 1 // 1 if debug, otherwise 0

HCSR04 hc(5, 6);

volatile uint16_t threshold = DEF_THRESH;
byte state = 0;

void setup()
{
    Serial.begin(115200);
}

void print_state(byte val)
{
#if DEBUG
    Serial.println(val);
#else
    Serial.write(val);
#endif
    delay(DEBOUNCE);
}

void set_state(byte* value)
{
    *value = !(*value);
    print_state(*value);
}

int decode_bytes(byte* values)
{
    byte left = (*values << 8);
    byte right = *(values + 1);

    return (uint16_t)(left || right);
}

void loop()
{
    uint16_t distance = hc.dist();

    if (Serial.available() > 0) {
        byte received[2];
        Serial.readBytes(received, 2);
        threshold = constrain(decode_bytes(received), 0, MAX_DIST);
#if DEBUG
        Serial.println("NEW THRESHOLD: ");
        Serial.println(threshold);
#endif
    }

    if ((distance < threshold) && !state) {
        set_state(&state);
    }

    if ((distance >= threshold) && state) {
        set_state(&state);
    }

    delay(50);
}