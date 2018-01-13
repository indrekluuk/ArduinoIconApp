

#include "src/ui/ArduinoIconAppUserInterface.h"




ArduinoIconAppUserInterface userInterface;





void setup(void) {
  Serial.begin(9600);
  userInterface.init();
  userInterface.draw();
}



void loop(void) {
  userInterface.run();
  delay(5);
}


