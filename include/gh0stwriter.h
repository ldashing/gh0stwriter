#ifndef GHOSTWIRTER_H
#define GHOSTWIRTER_H

#include "carriage.h"
#include "ascii-map.h"

#define LINE_SPACE   40     // Feed steps per new line
#define CHAR_SPACE   24     // Head steps between chars
// TODO: not used ?
#define TAPE_ADVANCE -25    // Tape steps per printed char

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

/*
 * Method for printing a whole string. It uses the printChar
 * method from above for each char in the string
 */
void printString(String, bool);

#endif

