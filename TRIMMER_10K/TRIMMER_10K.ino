#include <HCSR04.h>
#include <ResponsiveAnalogRead.h>

#define ANALOG_PIN A0 // select the input pin for the potentiometer

ResponsiveAnalogRead analog(ANALOG_PIN, true);
HCSR04 hc(5, 6);

volatile int threshold = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
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

void loop()
{
    int value = hc.dist();
    Serial.println(value);
    delay(50);
}

//Timer1 Overflow interrupt.
ISR(TIMER1_OVF_vect)
{
    analog.update();
    Serial.println(analog.getValue());
}
