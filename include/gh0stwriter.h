#ifndef GHOSTWIRTER_H
#define GHOSTWIRTER_H

#include "carriage.h"
#include "ascii-map.h"
#include "draw.h"

#define LINE_SPACE   40     // Feed steps per new line




void printArrayChar(char arrayToPrint[]);
/*
 * Starts a new line and resets the head
 */
void newLine();

/*
 * Method for printing a singe char at the current position
 * and then advance the head to the next position
 * or doing some special character stuff such as space or CR
 */
void printChar(char);

void fasterCharPrint(char);

/*
 * Method for printing a whole string. It uses the printChar
 * method from above for each char in the string
 */
void printString(String, bool);

#endif
