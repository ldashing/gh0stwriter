#ifndef DRAW_H
#define DRAW_H

#include "carriage.h"
#include "ascii-map.h"

// extern int currentHeadPos;

/*
 * Draw a two dimensional bool array relative to the carriage position
 */
void print2D(int, int, bool**);

/*
 * Print a 'pixel' (dot)
 *
 * Position is relative from the current carriage position + xy parameters
 */
void printPixelRelativ(int, int);

#endif

