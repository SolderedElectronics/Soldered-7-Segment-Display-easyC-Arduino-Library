/**
 **************************************************

   @file        attiny_firmware.ino
   @brief       Firmware for attiny.



   @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

#define PWM PA5

// Shift register pins
#define DATA_PIN  PA1
#define CLK_PIN   PA3
#define LATCH_PIN PA4

byte data[2];
bool f = 0;

int addr = DEFAULT_ADDRESS;

void setup()
{
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    pinMode(DATA_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLK_PIN, OUTPUT);

    pinMode(PWM, OUTPUT);
    analogWrite(PWM, 128);
}

void loop()
{
    if (f == 1)
    {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLK_PIN, LSBFIRST, ~data[0]);
        digitalWrite(LATCH_PIN, HIGH);

        analogWrite(PWM, data[1]);

        f = 0;
    }

    delay(10);
}


void receiveEvent(int howMany)
{
    if (Wire.available() == 2)
    {
        Wire.readBytes(data, 2);
        f = 1;
    }
}

void requestEvent()
{
}
