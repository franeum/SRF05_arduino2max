#include <Arduino.h>
#include <HCSR04.h>
#include <ResponsiveAnalogRead.h>

#define ANALOG_PIN A0 // select the input pin for the potentiometer
#define MAX_DIST 534 // cm
#define DEF_THRESH 50 // cm
#define DEBOUNCE 200 // msecs
#define DEBUG 1 // 1 if debug, otherwise 0

ResponsiveAnalogRead analog(ANALOG_PIN, true);
HCSR04 hc(5, 6);

volatile int threshold = DEF_THRESH;
byte state = 0;

void setup()
{
    Serial.begin(115200);
    cli();
    TCCR1A = 0x00;

    // prescaler a  1:64 (0.26214 secs)
    TCCR1B = 0b00000011;

    //reset del contatore
    TCNT1 = 0x0000;

    //abilita l'interrupt
    TIMSK1 = 0x01;
    sei();
}

void print_state(byte val)
{
#if DEBUG
    Serial.println(state);
#else
    Serial.write(state);
#endif
    delay(DEBOUNCE);
}

void loop()
{
    int distance = hc.dist();

    if (Serial.available() > 0) {
        // read the incoming byte:
        int serial_raw = Serial.read();

        // say what you got:
        Serial.print("I received: ");
        Serial.println(serial_raw, DEC);
    }

    if ((distance < threshold) && (state == 0)) {
        state = 1;
        print_state(state);
    }

    if ((distance >= threshold) && (state == 1)) {
        state = 0;
        print_state(state);
    }

    delay(50);
}

//Timer1 Overflow interrupt.
ISR(TIMER1_OVF_vect)
{
    analog.update();
    //threshold = analog.getValue();
    threshold = DEF_THRESH;
}