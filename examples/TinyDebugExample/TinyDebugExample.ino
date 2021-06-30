/**
  TinyDebug for Wokwi.com - demo project.

  TinyDebug allows use to log debug information from your ATtiny85 code
  using a Serial-like print interface.

  Check out the online example: https://wokwi.com/arduino/projects/300650387867697672
*/

#include "TinyDebug.h"

#define LED 2

void setup() {
  Debug.begin();
  Debug.println(F("Hello Tiny!"));
  pinMode(LED, OUTPUT);
}

int i = 0;
void loop() {
  delay(500);
  i++;
  Debug.print(F("Counter: "));
  Debug.println(i);
  digitalWrite(LED, !digitalRead(LED));
}
