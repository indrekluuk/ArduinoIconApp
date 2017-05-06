//
// Created by indrek on 25.03.2017.
//

#include "PBlocksIconsEditor.h"



void PBlocksIconsEditor::init() {
  display.init();
  display.draw(true);
}




void PBlocksIconsEditor::run() {
  display.run();
  delay(5);
}
