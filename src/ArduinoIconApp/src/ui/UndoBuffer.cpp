//
// Created by indrek on 13.01.2018.
//

#include "UndoBuffer.h"
#include "ArduinoIconAppUserInterface.h"



void UndoBuffer::init() {
  UI->copyActiveIconTo(undoBuffer[undoStart]);
}



void UndoBuffer::saveActiveIconToUndoBuffer() {
  undoIndex++;
  if (undoIndex >= UNDO_BUFFER_DEPTH) undoIndex = 0;
  undoEnd = undoIndex;

  if (undoEnd == undoStart) {
    undoStart++;
    if (undoStart >= UNDO_BUFFER_DEPTH) undoStart = 0;
  }
  UI->copyActiveIconTo(undoBuffer[undoEnd]);
  UI->tools.checkUndoAndRedo(true);
}




void UndoBuffer::loadActiveIconFromUndoBuffer() {
  uint8_t scale = UI->exampleView.scale;
  uint8_t hasBorder = UI->activeIcon.color.hasBorder;
  uint8_t hasBorder3d = UI->activeIcon.color.hasBorder3d;
  UI->setActiveIcon(undoBuffer[undoIndex]);
  UI->exampleView.scale = scale;
  UI->activeIcon.color.hasBorder = hasBorder;
  UI->activeIcon.color.hasBorder3d = hasBorder3d;

  UI->tools.checkUndoAndRedo(true);
  UI->refreshUpdatedActiveIcon(true, true, true);
}




void UndoBuffer::undo() {
  if (undoIndex != undoStart) {
    if (undoIndex == 0) {
      undoIndex = UNDO_BUFFER_DEPTH - 1;
    } else {
      undoIndex--;
    }
    loadActiveIconFromUndoBuffer();
  }
}


void UndoBuffer::redo() {
  if (undoIndex != undoEnd) {
    undoIndex++;
    if (undoIndex >= UNDO_BUFFER_DEPTH) undoIndex = 0;
    loadActiveIconFromUndoBuffer();
  }
}



bool UndoBuffer::isUndoAvailable() {
  return undoIndex != undoStart;
}



bool UndoBuffer::isRedoAvailable() {
  return undoIndex != undoEnd;
}



