#include "draw.h"

void print2D(int sizeX, int sizeY, bool **qrcode) {
    for (int i = 0; i < sizeY; i++) {
        int blankSpace = 0;
        for (int j = 0; j < sizeX; j++) {
            if (qrcode[i][j]) {
                head.move(blankSpace);
                currentHeadPos += blankSpace;
                blankSpace = 0;
                delay(1);
                printPixelRelativ(0, 0);
                blankSpace += 6;
            } else {
                blankSpace += 6;
            }
        }
        head.enable();
        head.move(-currentHeadPos);
        currentHeadPos = 0;
        delay(1);
        feed.enable();
        feed.move(5);
    }
    feed.enable();
    feed.move((-5 * sizeY) + 20);
}

void printPixelRelativ(int x, int y) {
    head.move(x);
    currentHeadPos += x;
    feed.move(y);

    turnDialTo(ascii_lookup['.']);
    delay(20);
    hammerHit();
    delay(20);

    tape.enable();
    tape.move(-9);
    delay(1);
    tape.move(-9);
    tape.disable();
}

void printPixelHere(){
    delay(13);
    hammerHit();
    //delay(5);
    tape.enable();
    tape.move(-18);
    tape.disable();
}
