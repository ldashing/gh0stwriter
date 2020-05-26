#include <Arduino.h>
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 100

// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 1


//(MOTOR_STEPS, DIR, STEP, SLEEP, M0, M1);
BasicStepperDriver feed(MOTOR_STEPS, 3, A1, A0);
BasicStepperDriver tape(MOTOR_STEPS, 9, 8, 7);
BasicStepperDriver dial(MOTOR_STEPS, 6, 5, 4);
//BasicStepperDriver dial(24, 6, 5, 4);
BasicStepperDriver head(MOTOR_STEPS, 12, 11, 10);

int lastChar=0;
int currentHeadPos=0;
String charTable = "_W)UIN?D\"C*R$LTAY&VZSPFB?E0987654321+?>^f@?wjmlv-,.zobudiaesrngchpky????qxt#?<?`??G?%JQ?X!O/K(H\'M:;= {";



void printChar(char charToPrint){
  Serial.print("[INFO]Print char ");
  int charNumber = charTable.lastIndexOf(charToPrint);
  Serial.print(charToPrint);
  Serial.print("=");
  Serial.println(charNumber);
  if (charNumber>=100) {
    switch (charNumber) {
      case 100:
      head.enable();
      head.move(25);
      //delay(100);

      head.disable();
      currentHeadPos=currentHeadPos+25;
      Serial.println("space");
      break;
      case 101:
      head.enable();
      head.move(-currentHeadPos);
      currentHeadPos=0;
      head.disable();
      feed.enable();
      feed.move(40);
      feed.disable();
      Serial.println("CR");
      break;

    }

  }else{
/*
    int toMove = 4*charNumber;

    if(toMove-lastChar>0){
      dial.move(toMove-lastChar+8);
      delay(15);
      dial.move(-8);
    }else{
      dial.move(toMove-lastChar);
    }

    Serial.println((toMove-lastChar)/4);
    lastChar = toMove;
*/
int toMove = 4*charNumber;
int diff = toMove-lastChar;

Serial.print("abs diff:");
Serial.println(abs(diff));

if(abs(diff)!=0){
  Serial.print("abs < 20 = extra move");
  dial.move(toMove-lastChar+8);
  delay(30);
  dial.move(-8);
}
/*else{
  dial.move(toMove-lastChar);
}*/

Serial.println((toMove-lastChar)/4);
lastChar = toMove;
    //dial.move(toMove);
    delay(20);
    //dial.disable();
    digitalWrite(A5, HIGH);
    delay(6);
    digitalWrite(A5, LOW);
    delay(10);
    //dial.enable();
    //dial.move(-toMove);



/*

for (int i = 0; i < 6; i++) {
  digitalWrite(A5, HIGH);
  delay(10);
  digitalWrite(A5, LOW);
  delay(15);
}
*/


delay(10);
    //dial.move(-4*charNumber);
    head.enable();
    head.move(25);
    delay(5);
    head.disable();
    currentHeadPos=currentHeadPos+25;
//25
    tape.enable();
    tape.move(-20);
    tape.disable();
    delay(50);
  }
  Serial.print("currentHeadPos: ");
Serial.println(currentHeadPos);
Serial.println("");
Serial.println("");
Serial.println("");
}

void printString(String stringToPrint, bool ln){
  for (size_t i = 0; i < stringToPrint.length(); i++) {
    if (currentHeadPos>1300) {
      head.enable();
      head.move(-currentHeadPos);
      currentHeadPos=0;
      head.disable();
      feed.enable();
      feed.move(30);
      feed.disable();
    }
    printChar(stringToPrint[i]);
  }
  if(ln){
    head.enable();
    head.move(-currentHeadPos);
    currentHeadPos=0;
    head.disable();
    feed.enable();
    feed.move(30);
    feed.disable();
  }

}
void xyMove(int x, int y){
  head.enable();
  feed.enable();
  head.move(x);
  feed.move(y);
  head.disable();
  feed.disable();
}
void hit(){
  digitalWrite(A5, HIGH);
  delay(20);
  digitalWrite(A5, LOW);
  delay(20);
}
void setup() {

    Serial.begin(9600);

    feed.begin(RPM, MICROSTEPS);
    tape.begin(RPM, MICROSTEPS);
    dial.begin(100, 2);
    head.begin(RPM, MICROSTEPS);

    feed.setEnableActiveState(LOW);
    tape.setEnableActiveState(LOW);
    dial.setEnableActiveState(LOW);
    head.setEnableActiveState(LOW);

    feed.disable();
    tape.disable();
    dial.disable();
    head.disable();
    pinMode(2, INPUT_PULLUP);
    pinMode(A5,OUTPUT);
    digitalWrite(A5, LOW);
    pinMode(A2,OUTPUT);

    digitalWrite(A2, HIGH);
    delay(1);
    digitalWrite(A2, LOW);
    delay(1);
    digitalWrite(A2, HIGH);




    head.enable();
    while(digitalRead(2)==HIGH){
      head.move(-1);
      delay(1);
      //delay();
      //Serial.println("backing of...");
    }
    head.disable();

    dial.enable();
    dial.move(-4*100);
    //dial.disable();
    delay(100);


        head.enable();

          head.move(70);

        head.disable();

    //dial.enable();
  //  delay(5000);
    //dial.move(-3);
  //  delay(500);
    //dial.disable();
//dial.move(48*4);
//dial.move(-2*4);



   printString(".. .  .  ..   ",true);
   printString("..  . ..    . ",true);
   printString(".. .  .  .   .",true);
  // printString("The ULN2003 is known for its high-current, high-voltage capacity. The drivers can be paralleled for even higher current output. Even further, stacking one chip on top of another, both electrically and physically, has been done. Generally it can also be used for interfacing with a stepper motor, where the motor requires high ratings which cannot be provided by other interfacing devices. ",true);
  //printString("A unipolar stepper motor has one winding with center tap per phase. Each section of windings is switched on for each direction of magnetic field. Since in this arrangement a magnetic pole can be reversed without switching the direction of current, the commutation circuit can be made very simple (e.g., a single transistor) for each winding. Typically, given a phase, the center tap of each winding is made common: giving three leads per phase and six leads for a typical two phase motor. Often, these two phase commons are internally joined, so the motor has only five leads.", true);
  // printString("A microcontroller or stepper motor controller can be used to activate the drive transistors in the right order, and this ease of operation makes unipolar motors popular with hobbyists; they are probably the cheapest way to get precise angular movements. For the experimenter, the windings can be identified by touching the terminal wires together in PM motors. If the terminals of a coil are connected, the shaft becomes harder to turn. One way to distinguish the center tap (common wire) from a coil-end wire is by measuring the resistance. Resistance between common wire and coil-end wire is always half of the resistance between coil-end wires. This is because there is twice the length of coil between the ends and only half from center (common wire) to the end. A quick way to determine if the stepper motor is working is to short circuit every two pairs and try turning the shaft. Whenever a higher than normal resistance is felt, it indicates that the circuit to the particular winding is closed and that the phase is working. ", true);

   //printString("Lorem ipsum dolor sit amet, consetetur sadipscing elitr,{ sed diam nonumy eirmod tempor invidunt ut labore{ et dolore magna aliquyam erat, sed diam voluptua.{ At vero eos et accusam et justo duo dolores et ea rebum. {Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. {Lorem ipsum dolor sit amet, consetetur sadipscing elitr,{ sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat,{ sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. {Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.",true);
    //printString("was?",true);
    //dial.move(1);
}

void loop() {
  /*
dial.move(4);
delay(2000);
digitalWrite(A5, HIGH);
delay(20);
digitalWrite(A5, LOW);
delay(500);
head.enable();

  head.move(30);

head.disable();
*/
printPixelRelativ(0, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);

printPixelRelativ(2, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(-1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(1, 0);



printPixelRelativ(18,2);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);

printPixelRelativ(2, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(-1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(1, 0);

printPixelRelativ(-26,-19);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(-1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);
printPixelRelativ(0, 1);

printPixelRelativ(2, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(-1, 0);
printPixelRelativ(0, 1);
printPixelRelativ(1, 0);

printPixelRelativ(4, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);
printPixelRelativ(0, -1);

printPixelRelativ(3, 1);
printPixelRelativ(0, 1);
printPixelRelativ(-1, 0);
printPixelRelativ(1, 1);
printPixelRelativ(1, 1);
printPixelRelativ(0, -1);
printPixelRelativ(-1, -1);
printPixelRelativ(-1, -1);
printPixelRelativ(0, -1);
printPixelRelativ(1, 0);
printPixelRelativ(1, 0);
printPixelRelativ(0, 1);

















}
