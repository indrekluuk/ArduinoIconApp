

#include "PBlocksIconsEditor.h"




PBlocksIconsEditor module;




void setup(void) {
  Serial.begin(9600);
  module.init();
}



void loop(void) {
  module.run();
}


