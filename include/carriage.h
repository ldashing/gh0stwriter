#ifndef CARRIAGE_H
#define CARRIAGE_H

#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200     // Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define RPM         100     // Seames to be the best
#define MICROSTEPS  1       // 1=full step, 2=half step etc.

#define CHAR_SPACE  24      // steps for the carriage to move for one character
#define TAPE_SPACE -24      // steps for the tape to refresh color for one character

#define RESET_POS_PIN PB13

extern BasicStepperDriver feed;
extern BasicStepperDriver tape;
extern BasicStepperDriver dial;
extern BasicStepperDriver head;

#define MAX_HEAD_POS 1300   // Maximal head position

typedef struct {
    int x;
    int y;
} Position;

extern Position carriage;
extern int currentHeadPos; // Save the current head posiion (x)

/*
 * Hits the hammer as fast as possible
 */
void hammerHit();

/*
 * Move carriage the Home position (x = 0)
 */
void carriageReturn();

/*
 *
 */
void step();

/*
 *
 */
void refreshTape();

/*
 * Turn the charecter dial to the given position (mapped to ascii in the ascii map)
 */
void turnDialTo(char pos);

/*
 * Reset the dail and return to the last head pos if needed
 */
void dialReset();

/*
 * A xy move relative to the current location (no absolut coords)
 */
void xyMove(int, int);

#endif

