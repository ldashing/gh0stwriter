#ifndef DRAW_H
#define DRAW_H

#include "gh0stwriter.h"
#include "carriage.h"

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

