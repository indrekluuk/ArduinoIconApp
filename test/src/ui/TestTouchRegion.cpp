


#include "gtest/gtest.h"
#include "src/ui/ArduinoIconAppUserInterface.h"


class TouchableItem : public Touchable {
  bool touch(uint16_t x, uint16_t y) {}
  void hold(uint16_t x, uint16_t y) {}
  void release(uint16_t x, uint16_t y) {}

};


TEST(TestTouchRegion, constructDeconstructRegions) {
  TouchHandler touchHandler;

  EXPECT_EQ(0, touchHandler.getRegionCount());
  {
    TouchableItem t1;
    EXPECT_EQ(1, touchHandler.getRegionCount());

    {
      TouchableItem t2;
      EXPECT_EQ(2, touchHandler.getRegionCount());
    }

    EXPECT_EQ(1, touchHandler.getRegionCount());
  }

  EXPECT_EQ(0, touchHandler.getRegionCount());
}




TEST(TestTouchRegion, constructDeconstructDynamicallyOutOfOrder) {
  TouchHandler touchHandler;

  TouchableItem * t1 = nullptr;
  TouchableItem * t2 = nullptr;
  TouchableItem * t3 = nullptr;

  EXPECT_EQ(0, touchHandler.getRegionCount());

  t1 = new TouchableItem();
  EXPECT_EQ(1, touchHandler.getRegionCount());
  t2 = new TouchableItem();
  EXPECT_EQ(2, touchHandler.getRegionCount());
  t3 = new TouchableItem();
  EXPECT_EQ(3, touchHandler.getRegionCount());

  delete t2;
  EXPECT_EQ(2, touchHandler.getRegionCount());
  delete t1;
  EXPECT_EQ(1, touchHandler.getRegionCount());
  t2 = new TouchableItem();
  EXPECT_EQ(2, touchHandler.getRegionCount());
  delete t3;
  EXPECT_EQ(1, touchHandler.getRegionCount());
  delete t2;
  EXPECT_EQ(0, touchHandler.getRegionCount());
}




