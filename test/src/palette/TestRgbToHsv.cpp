


#include "gtest/gtest.h"
#include "src/palette/RgbToHsv.h"


TEST(TestRgbToHsv, testConvertColors) {

  RgbToHsv hsv1(0x00, 0x00, 0x00);
  EXPECT_EQ(0, hsv1.H);
  EXPECT_EQ(0, hsv1.S);
  EXPECT_EQ(0, hsv1.V);

  RgbToHsv hsv2(0xFF, 0xFF, 0xFF);
  EXPECT_EQ(0, hsv2.H);
  EXPECT_EQ(0, hsv2.S);
  EXPECT_EQ(1, hsv2.V);

  RgbToHsv hsv3(0xFF, 0x00, 0x00);
  EXPECT_EQ(0, hsv3.H);
  EXPECT_EQ(1, hsv3.S);
  EXPECT_EQ(1, hsv3.V);

  RgbToHsv hsv4(0x00, 0xFF, 0x00);
  EXPECT_EQ(((float)120) / 360, hsv4.H);
  EXPECT_EQ(1, hsv4.S);
  EXPECT_EQ(1, hsv4.V);

  RgbToHsv hsv5(0x00, 0x00, 0xFF);
  EXPECT_EQ(((float)240) / 360, hsv5.H);
  EXPECT_EQ(1, hsv5.S);
  EXPECT_EQ(1, hsv5.V);

  // test 0..60
  RgbToHsv hsv6(0xAA, 0x99, 0x33);
  EXPECT_NEAR(((float)51) / 360, hsv6.H, 0.01);
  EXPECT_NEAR(0.7, hsv6.S, 0.01);
  EXPECT_EQ(((float)2) / 3, hsv6.V);

  // test 60..120
  RgbToHsv hsv7(0x21, 0x40, 0x08);
  EXPECT_NEAR(((float)93) / 360, hsv7.H, 0.01);
  EXPECT_NEAR(0.88, hsv7.S, 0.01);
  EXPECT_NEAR(0.25, hsv7.V, 0.01);

  // 120..180
  RgbToHsv hsv8(0x35, 0xF2, 0x81);
  EXPECT_NEAR(((float)144) / 360, hsv8.H, 0.01);
  EXPECT_NEAR(0.781, hsv8.S, 0.01);
  EXPECT_NEAR(0.949, hsv8.V, 0.01);

  // 180..240
  RgbToHsv hsv9(0xDE, 0xAF, 0x99);
  EXPECT_NEAR(((float)19) / 360, hsv9.H, 0.01);
  EXPECT_NEAR(0.31, hsv9.S, 0.01);
  EXPECT_NEAR(0.87, hsv9.V, 0.01);

  // 240..300
  RgbToHsv hsv10(0x78, 0x3D, 0x7D);
  EXPECT_NEAR(((float)295) / 360, hsv10.H, 0.01);
  EXPECT_NEAR(0.51, hsv10.S, 0.01);
  EXPECT_NEAR(0.49, hsv10.V, 0.01);

  // 300..360
  RgbToHsv hsv11(0x7A, 0x4E, 0x73);
  EXPECT_NEAR(((float)310) / 360, hsv11.H, 0.01);
  EXPECT_NEAR(0.36, hsv11.S, 0.01);
  EXPECT_NEAR(0.48, hsv11.V, 0.01);

  // 300..360
  RgbToHsv hsv12(0x7A, 0x4E, 0x54);
  EXPECT_NEAR(((float)352) / 360, hsv12.H, 0.01);
  EXPECT_NEAR(0.36, hsv12.S, 0.01);
  EXPECT_NEAR(0.48, hsv12.V, 0.01);

}


