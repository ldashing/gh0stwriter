#include "carriage.h"

// TODO: convert to Position struct (carriage variable) and also save y pos
int currentHeadPos = 0; // Save the current head posiion (x)


void hammerHit() {
    digitalWrite(PB12, HIGH);
    delay(10);
    digitalWrite(PB12, LOW);
    delay(10);
}

void carriageReturn() {
    head.enable();
    head.move(0);
    carriage.x = 0;
    head.disable();
}

void dialReset() {
    tape.enable();
    head.enable();

    do {
        tape.move(1);
        delay(2);
    } while(digitalRead(PB13) == LOW);

    do {
        tape.move(1);
        delay(2);
    } while(digitalRead(PB13) == HIGH);

    do {
        tape.move(1);
        delay(2);
    } while(digitalRead(PB13) == LOW);

    while (digitalRead(PB13) == HIGH) {
        head.move(-1);
        delay(2);
    }
    head.disable();

    dial.enable();
    dial.move(-4 * 100);
    delay(100);

    head.enable();
    head.move(70);
    head.disable();

    if (currentHeadPos > 0) {
        head.enable();
        head.move(currentHeadPos);
        head.disable();
    }
    lastChar = 0;
}

void xyMove(int x, int y) {
    head.move(x);
    feed.move(y);
}

