#include <Arduino.h>
#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200		// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define RPM 100			//Seames to be the best
#define MICROSTEPS 1		// 1=full step, 2=half step etc.
/*
//name(MOTOR_STEPS, DIR, STEP, SLEEP, M0, M1);
BasicStepperDriver feed(MOTOR_STEPS, 3, A1, A0);
BasicStepperDriver tape(MOTOR_STEPS, 9, 8, 7);
BasicStepperDriver dial(MOTOR_STEPS, 6, 5, 4);
BasicStepperDriver head(MOTOR_STEPS, 12, 11, 10);
 */
BasicStepperDriver feed (MOTOR_STEPS, PA6, PA5, PA7);
BasicStepperDriver tape (MOTOR_STEPS, PB7, PB8, PB0);
BasicStepperDriver dial (MOTOR_STEPS, PA15, PB3, PB10);
BasicStepperDriver head (MOTOR_STEPS, PB5, PB6, PB1);

//some configuration:
int lineSpace = 40;		//Feed steps per new line
int charSpaceing = 24;		//Head steps between chars
int tapeAdvance = -25;		//Tape steps per printed char
int maxHeadPos = 1300;		//Maximal head position

int lastChar = 0;		//Save the last char that was printed
int currentHeadPos = 0;		//Save the current head position (x coord)

//The char table with all avalable chars and ther position on the dial/wheel
String charTable = "_W)UIN?D\"C*R$LTAY&VZSPFB?E0987654321+?>^f@?wjmlv-,.zobudiaesrngchpky????qxt#?<?`??G?%JQ?X!O/K(H\'M:;= {";

void
recvWithEndMarker ()
{
	int rc = 0;
	if (Serial.available () > 0)
	{
		rc = Serial.read ();
		if (rc >= 0) {
			printChar((char)rc);
		}
	}
}

/*
   Hits the hammer as fast as possible
 */
	void
hammerHit ()
{
	digitalWrite (PB12, HIGH);
	delay (10);
	digitalWrite (PB12, LOW);
	delay (10);
}

/*
   Starts a new line and resets the head
 */
	void
newLine ()
{
	head.enable ();
	Serial.println ("backing of ");
	Serial.print (-currentHeadPos);
	head.move (-currentHeadPos);
	currentHeadPos = 0;
	//head.disable();
	feed.enable ();
	feed.move (lineSpace);
	feed.disable ();
	head.disable ();
}

/*
   Method for printing a singe char at the current position and than advance the head to the next position or doing some special char stuff such as space or CR
 */
void printChar (char charToPrint) {
	int charNumber = charTable.lastIndexOf (charToPrint);
	if (charNumber >= 100 && charNumber >= 0)
	{				//Some special chars:
		Serial.print ("[INFO]Special char :");
		Serial.print (charToPrint);
		Serial.print (" char num: ");
		Serial.println (charNumber);
		switch (charNumber)
		{
			case 100:		//White space
				Serial.println ("space");
				head.enable ();
				head.move (charSpaceing);
				currentHeadPos += charSpaceing;
				//head.disable();
				break;
			case 101:		//Cardrige return(reset head to 0<x=0> and advance the paper<y-1>)
				Serial.println ("CR");
				head.enable ();
				head.move (-currentHeadPos);
				currentHeadPos = 0;
				//head.disable();
				feed.enable ();
				feed.move (40);
				feed.disable ();
				break;
		}
	} else if (charNumber >= 0) {
		Serial.print ("[INFO]Printing a char :");
		Serial.print (charToPrint);
		Serial.print (" Pos on wheel: ");
		Serial.println (charNumber);

		int toMove = 4 * charNumber;
		int diff = toMove - lastChar;

		Serial.print ("abs diff:");
		Serial.println (abs (diff));

		if (abs (diff) != 0)
		{
			Serial.print ("abs diff > 0");
			dial.move (toMove - lastChar + 8);
			delay (30);
			dial.move (-8);
		}

		Serial.println ((toMove - lastChar) / 4);
		lastChar = toMove;
		delay (20);
		hammerHit ();

		head.enable ();
		head.move (charSpaceing);
		//      head.disable();
		currentHeadPos += charSpaceing;

		tape.enable ();
		tape.move (-12);
		delay (1);
		tape.move (-12);
		tape.disable ();
	} else {
		// This would execute when the character to print is not in the charTable
		printChar('?');
	}
	Serial.print ("currentHeadPos: ");
	Serial.println (currentHeadPos);
	Serial.print ("\n\n\n");
	head.disable ();
}

/*
   Method for printing a whole string. It uses the printChar method from above for each char in the string
 */
	void
printString (String stringToPrint, bool ln)
{
	for (size_t i = 0; i < stringToPrint.length (); i++)
	{
		if (currentHeadPos >= maxHeadPos)
		{
			newLine ();
		}
		printChar (stringToPrint[i]);
	}
	if (ln)
	{
		newLine ();
	}
}

/*
   A xy move relative to the current location (no absolut coords)
 */
	void
xyMove (int x, int y)
{
	head.enable ();
	feed.enable ();
	head.move (x);
	feed.move (y);
	head.disable ();
	feed.disable ();
}

/*
   Reset the dail and return to the last head pos if needed
 */
	void
dialReset ()
{
	head.enable ();
	while (digitalRead (PB13) == HIGH)
	{
		head.move (-1);
		delay (1);
	}
	head.disable ();

	dial.enable ();
	dial.move (-4 * 100);
	delay (100);

	head.enable ();
	head.move (70);
	head.disable ();

	if (currentHeadPos > 0)
	{
		head.enable ();
		head.move (currentHeadPos);
		head.disable ();
	}
}

	void
setup ()
{
	Serial.begin (115200);
	Serial.print ("Ready...");

	feed.begin (RPM, MICROSTEPS);
	tape.begin (RPM, MICROSTEPS);
	dial.begin (100, 2);
	head.begin (RPM, MICROSTEPS);

	feed.setEnableActiveState (LOW);
	tape.setEnableActiveState (LOW);
	dial.setEnableActiveState (LOW);
	head.setEnableActiveState (LOW);

	feed.disable ();
	tape.disable ();
	dial.disable ();
	head.disable ();

	pinMode (PB13, INPUT_PULLUP);
	pinMode (PB12, OUTPUT);
	digitalWrite (PB12, LOW);
	pinMode (PB12, OUTPUT);

	digitalWrite (PB4, HIGH);
	delay (1);
	digitalWrite (PB4, LOW);
	delay (1);
	digitalWrite (PB4, HIGH);

	dialReset ();
}

	void
printPixelRelativ (int x, int y)
{
	head.move (6 * x);
	currentHeadPos += (6 * x);
	feed.enable ();
	feed.move (-5 * y);

	int toMove = 4 * charTable.lastIndexOf ('.');
	int diff = toMove - lastChar;

	if (abs (diff) != 0)
	{
		dial.move (toMove - lastChar + 8);
		delay (30);
		dial.move (-8);
	}
	lastChar = toMove;

	delay (20);
	hammerHit ();

	tape.enable ();
	tape.move (-9);
	delay (1);
	tape.move (-9);
	tape.disable ();




}

	void
print2D (int sizeX, int sizeY)
{
	for (int i = 0; i < sizeY; i++)
	{
		int blankSpace = 0;
		for (int j = 0; j < sizeX; j++)
		{
			if (qrcode[i][j])
			{
				head.move (blankSpace);
				currentHeadPos += blankSpace;
				blankSpace = 0;
				delay (1);
				printPixelRelativ (0, 0);
				blankSpace += 6;

			}
			else
			{
				blankSpace += 6;
			}
		}
		head.enable ();
		head.move (-currentHeadPos);
		currentHeadPos = 0;
		delay (1);
		feed.enable ();
		feed.move (5);
	}
	feed.enable ();
	feed.move ((-5 * sizeY) + 20);
}

	void
loop ()
{
	recvWithEndMarker ();
}
