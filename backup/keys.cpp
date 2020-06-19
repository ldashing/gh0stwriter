#include <Arduino.h>
#include <Keyboard.h>

void setup() {
  delay(10000);
    Keyboard.begin();
    Keyboard.print("Hello!");
}

void loop() {
  // put your main code here, to run repeatedly:
}
