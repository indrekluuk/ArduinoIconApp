cmake_minimum_required(VERSION 3.2)
project(ArduinoIconApp)



# PlatformIO build targets
# Must init platformio. See: PlatformIO_CLion_init.txt
add_subdirectory(src)






# init Google Test target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# fake arduino headers
include_directories(test/fake)
# project headers
include_directories(src/ArduinoIconApp)
# gtest headers
include_directories(${gtest_SOURCE_DIR}/include)


add_executable(runTests
        test/fake/Arduino.cpp
        test/fake/MCUFRIEND_kbv.cpp
        test/fake/avr/pgmspace.cpp

        src/ArduinoIconApp/src/lib/Touch-Screen-Library_mod/TouchScreen.cpp
        src/ArduinoIconApp/src/lib/MCUFRIEND_kbv_mod/MCUFRIEND_kbv.cpp
        src/ArduinoIconApp/src/lib/Adafruit_GFX_Library_mod/Adafruit_GFX.cpp

        src/ArduinoIconApp/src/ui/TouchHandler.cpp
        src/ArduinoIconApp/src/ui/ArduinoIconAppUserInterface.cpp
        src/ArduinoIconApp/src/ui/CalibrationView.cpp
        src/ArduinoIconApp/src/ui/DrawingGridView.cpp
        src/ArduinoIconApp/src/ui/ColorPickerView.cpp
        src/ArduinoIconApp/src/ui/ExampleView.cpp
        src/ArduinoIconApp/src/ui/ColorPickerButton.cpp
        src/ArduinoIconApp/src/ui/ColorPickerPalette.cpp
        src/ArduinoIconApp/src/ui/ColorPickerBrightnessBar.cpp
        src/ArduinoIconApp/src/ui/Button.cpp
        src/ArduinoIconApp/src/ui/Tools.cpp
        src/ArduinoIconApp/src/ui/Toolbar.cpp
        src/ArduinoIconApp/src/screen/TFT.cpp
        src/ArduinoIconApp/src/screen/Font.cpp
        src/ArduinoIconApp/src/screen/Colors.cpp
        src/ArduinoIconApp/src/icons/ProgMemIcons.cpp
        src/ArduinoIconApp/src/storage/IconStorage.cpp
        src/ArduinoIconApp/src/palette/PaletteGenerator.cpp
        src/ArduinoIconApp/src/palette/RgbToHsv.cpp

        test/src/ui/TestTouchRegion.cpp
        test/src/palette/TestRgbToHsv.cpp
        )
target_compile_definitions(runTests PRIVATE ARDUINO=180)

# link
add_subdirectory(test/lib/gtest-1.7.0)
target_link_libraries(runTests gtest_main)





