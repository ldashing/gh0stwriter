#include <Arduino.h>

#include "gh0stwriter.h"

byte escapeCounter = 0;
long previousMillis = 0;


void recvSerialData () {
    unsigned long currentMillis = millis();
    char rc = 0;
    if (Serial.available() > 0){
        previousMillis = currentMillis;
        rc = Serial.read();

        if (rc >= 0) {
            printChar(rc);
        }

        if (rc == '<') {
            escapeCounter++;
            if (escapeCounter == 5) {
                printString("Dot mode.", true);
                int blankSpace = 0;
                rc = 0;
                head.enable();
                head.move(100);
                currentHeadPos = 0;
                while (rc != '3') {
                    rc = 0;
                    rc = Serial.read();
                    if (rc == '1') {
                        head.move(blankSpace);
                        currentHeadPos += blankSpace;
                        blankSpace = 0;
                        delay(1);
                        printPixelRelativ(0, 0);
                        blankSpace += 6;
                    }
                    if (rc == '0') {
                        blankSpace += 6;
                    }
                    if (rc == '2') {
                        blankSpace = 0;
                        head.enable();
                        head.move(-currentHeadPos);
                        currentHeadPos = 0;
                        delay(1);
                        feed.enable();
                        feed.move(5);
                    }

                }
                newLine();
                head.move(-100);
                currentHeadPos = 0;
                escapeCounter = 0;
            }
        } else {
            escapeCounter = 0;
        }
    } else {
        if (currentMillis - previousMillis >= 50000) {
            previousMillis = currentMillis;
            feed.disable();
            tape.disable();
            dial.disable();
            head.disable();

            while (Serial.available() == 0) {}

            digitalWrite(PB4, HIGH);
            delay(1);
            digitalWrite(PB4, LOW);
            delay(1);
            digitalWrite(PB4, HIGH);

            dialReset();
            tape.move(-20);
        }
    }
}

void setup() {
    Serial.begin(9600);
    //Serial.print("Ready...");

    feed.begin(RPM, MICROSTEPS);
    tape.begin(RPM, MICROSTEPS);
    dial.begin(100, 2);
    head.begin(RPM, MICROSTEPS);

    feed.setEnableActiveState(LOW);
    tape.setEnableActiveState(LOW);
    dial.setEnableActiveState(LOW);
    head.setEnableActiveState(LOW);

    feed.disable();
    tape.disable();
    dial.disable();
    head.disable();

    pinMode(PB13, INPUT_PULLUP);
    pinMode(PB12, OUTPUT);
    digitalWrite(PB12, LOW);
    pinMode(PB12, OUTPUT);

    digitalWrite(PB4, HIGH);
    delay(1);
    digitalWrite(PB4, LOW);
    delay(1);
    digitalWrite(PB4, HIGH);

    dialReset();
}

void loop() {
    recvSerialData ();
}

