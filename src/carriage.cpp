#include "carriage.h"

// TODO: convert to Position struct (carriage variable) and also save y pos
int currentHeadPos = 0;
// Position carriage = {0, 0};
int lastChar = 0;

BasicStepperDriver feed (MOTOR_STEPS, PA6, PA5, PA7);
BasicStepperDriver tape (MOTOR_STEPS, PB7, PB8, PB0);
BasicStepperDriver dial (MOTOR_STEPS, PA15, PB3, PB10);
BasicStepperDriver head (MOTOR_STEPS, PB5, PB6, PB1);

MultiDriver multiAxle(dial, head, tape);
MultiDriver blank( head, tape);

void hammerHit() {
    digitalWrite(PB12, HIGH);
    delay(10);
    digitalWrite(PB12, LOW);
    //delay(10);
}

void carriageReturn() {
    head.enable();
    head.move(0);
    carriage.x = 0;
    head.disable();
}

void step() {
    head.enable();
    head.move(CHAR_SPACE);
    currentHeadPos += CHAR_SPACE;
}

void refreshTape() {
    tape.enable();
    tape.move(TAPE_SPACE);
    tape.disable();
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

void turnDialTo(char pos) {
    int diff = pos - lastChar;
    if (diff!=0) {
        if (diff > DIAL_SIZE / 2) {
            diff = diff - DIAL_SIZE;
        } else if (diff < DIAL_SIZE / 2 * -1) {
            diff = diff + DIAL_SIZE;
        }
        int dialtomove = (4 * diff)-10;
        dial.move(dialtomove);
        delay(10);
        dial.move(10);
        lastChar = pos;
    }
}

void fasterCharPrint(char pos){
    int diff = pos - lastChar;

    if (diff!=0) {

        if (diff > DIAL_SIZE / 2) {
            diff = diff - DIAL_SIZE;
        } else if (diff < DIAL_SIZE / 2 * -1) {
            diff = diff + DIAL_SIZE;
        }

        int dialtomove = (4 * diff)-10;
        multiAxle.enable();
        multiAxle.move(dialtomove, CHAR_SPACE, TAPE_SPACE);
        tape.disable();
        head.disable();
        currentHeadPos += CHAR_SPACE;

        delay(10);
        dial.move(10);
        //delay(100);

        head.disable();
        tape.disable();


    }else{
        /*
        head.enable();
        tape.enable();
        multiAxle.enable();
        multiAxle.move(0, CHAR_SPACE, TAPE_SPACE);
        head.disable();
        tape.disable();
        */

        blank.enable();
        blank.move(CHAR_SPACE, TAPE_SPACE);
        blank.disable();
        tape.disable();
        currentHeadPos += CHAR_SPACE;

/*
        step();
        refreshTape();
        */
    }

    hammerHit();


    lastChar = pos;
}

void xyMove(int x, int y) {
    head.move(x);
    feed.move(y);
}
