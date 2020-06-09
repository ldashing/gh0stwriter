#ifndef CARRIAGE_H
#define CARRIAGE_H

#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200     // Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define RPM         100     // Seames to be the best
#define MICROSTEPS  1       // 1=full step, 2=half step etc.

#define RESET_POS_PIN PB13

BasicStepperDriver feed (MOTOR_STEPS, PA6, PA5, PA7);
BasicStepperDriver tape (MOTOR_STEPS, PB7, PB8, PB0);
BasicStepperDriver dial (MOTOR_STEPS, PA15, PB3, PB10);
BasicStepperDriver head (MOTOR_STEPS, PB5, PB6, PB1);

#define MAX_HEAD_POS 1300   // Maximal head position

typedef struct {
    int x;
    int y;
} Position;

Position carriage;

/*
 * Hits the hammer as fast as possible
 */
void hammerHit();

/*
 * Move carriage the Home position (x = 0)
 */
void carriageReturn();

/*
 * Reset the dail and return to the last head pos if needed
 */
void dialReset();

/*
 * A xy move relative to the current location (no absolut coords)
 */
void xyMove(int, int);

#endif

