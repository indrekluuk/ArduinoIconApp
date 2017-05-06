//
// Created by indrek on 6.05.2017.
//

#ifndef PBLOCKICONS_EXAMPLEVIEW_H
#define PBLOCKICONS_EXAMPLEVIEW_H


#include "TouchHandler.h"



class ExampleView : public Touchable {


public:
    void init();
    bool tap(uint16_t x, uint16_t y, bool hold) override;

    void draw(bool redrawAll);
    void reDrawExamples();

};


#endif //PBLOCKICONS_EXAMPLEVIEW_H
