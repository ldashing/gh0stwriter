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

    int toMove = 4 * ascii_lookup['.'];
    int diff = toMove - lastChar;

    if (abs(diff) != 0) {
        dial.move(toMove - lastChar + 8);
        delay(30);
        dial.move(-8);
    }
    lastChar = toMove;

    delay(20);
    hammerHit();

    tape.enable();
    tape.move(-9);
    delay(1);
    tape.move(-9);
    tape.disable();
}

