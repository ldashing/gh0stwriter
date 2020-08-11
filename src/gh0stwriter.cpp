#include "gh0stwriter.h"

/*
char bracketOpen[] = {
    B11000,
    B10000,
    B10000,
    B10000,
    B11000,
};
*/
char bracketOpen[] = {
    B10101,
    B01010,
    B10101,
    B01010,
    B10101

};



void newLine() {
    head.enable();
    head.move(-currentHeadPos);
    currentHeadPos = 0;
    feed.enable();
    feed.move(LINE_SPACE);
    feed.disable();
    head.disable();
}

void printArrayChar(char arrayToPrint[]){


    int localX=0;
    int localY=0;

    turnDialTo(ascii_lookup['.']);

    feed.enable();
    head.enable();
    xyMove(0, -25);
    localY=localY-25;
    tape.enable();
    tape.move(-18);
    tape.disable();
    for(int i=0;i<5;i++){
        int blankSpace = 0;
        for(int j=16;j>0;j/=2){
            if(arrayToPrint[i]&j){
                head.move(blankSpace);
                delay(10);
                blankSpace = 0;
                printPixelHere();
                blankSpace += 6;
                delay(10);
            }else{
                blankSpace += 6;

            }
        }
        localX=blankSpace;
        blankSpace = 0;
        head.enable();
        head.move(-localX);
        localX = 0;
        delay(1);
        feed.enable();
        feed.move(5);
    }
    xyMove(CHAR_SPACE, localY);
    feed.disable();
}

void printChar(char charToPrint) {
    char charNumber = ascii_lookup[(int)charToPrint];
    // Some special characters
    if (charNumber >= 100) {
        switch (charNumber) {
            // White space
            case 100:
                head.enable();
                head.move(CHAR_SPACE);
                head.disable();
                currentHeadPos += CHAR_SPACE;
                break;
            // Cardrige return(reset head to 0<x=0> and advance the paper<y-1>) LF
            case 101:

                head.enable();
                head.move(-currentHeadPos);
                currentHeadPos = 0;
                feed.enable();
                feed.move(40);
                feed.disable();
                break;
            // [
            case 102:

                head.enable();
                feed.enable();
                xyMove(0, 6);
                printPixelRelativ(0, 0);
                printPixelRelativ(0, -6);
                printPixelRelativ(0, -6);
                printPixelRelativ(0, -6);
                printPixelRelativ(0, -6);
                printPixelRelativ(4, 0);
                printPixelRelativ(0, 24);
                xyMove(-4 + CHAR_SPACE, -6);
                head.disable();
                feed.disable();

                //printArrayChar(bracketOpen);
                break;
            // ]
            case 103:
                head.enable();
                feed.enable();
                xyMove(0, 6);
                printPixelRelativ(0, 0);
                printPixelRelativ(4, 0);
                printPixelRelativ(0, -6);
                printPixelRelativ(0, -6);
                printPixelRelativ(0, -6);
                printPixelRelativ(0, -6);
                printPixelRelativ(-4, 0);
                xyMove(CHAR_SPACE, 24-6);
                head.disable();
                feed.disable();
                break;
            // '\'
            case 104:
                head.enable();
                feed.enable();
                xyMove(-6, -16);
                printPixelRelativ(0, 0);
                printPixelRelativ(3, 4);
                printPixelRelativ(3, 4);
                printPixelRelativ(3, 4);
                printPixelRelativ(3, 4);
                xyMove(-6 + CHAR_SPACE, 0);
                head.disable();
                feed.disable();
                break;
            // '{'
            case 105:
                printChar('(');
                head.enable();
                feed.enable();
                xyMove(-CHAR_SPACE - 5, -4);
                printPixelRelativ(0, 0);
                xyMove(5 + CHAR_SPACE, 4);
                head.disable();
                feed.disable();
                break;
            case 254:
                //do nothing
                break;
            default:
                printChar('?');
                break;
        }
    } else if (charNumber >= 0) {
        /*
        // turn Dial to typed character
        turnDialTo(charNumber);
        // wait for the dial to finish tuning
        delay(10);
        // its hammer time !!! (print the character for real)
        hammerHit();
        // move carriage by the width of a generic character
        step();
        // turn the tape one character wide
        refreshTape();
        */
        fasterCharPrint(charNumber);
    }
    //head.disable();
}

void printString(String stringToPrint, bool ln) {
    for (size_t i = 0; i < stringToPrint.length(); i++) {
        if (currentHeadPos >= MAX_HEAD_POS) {
            newLine();
        }
        printChar(stringToPrint[i]);
    }
    if (ln) {
        newLine();
    }
}
