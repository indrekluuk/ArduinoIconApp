cmake_minimum_required(VERSION 3.2)
project(PBlockIcons)



# PlatformIO build targets
# Must init platformio. See: PlatformIO_CLion_init.txt
add_subdirectory(src)






# init Google Test target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# fake arduino headers
include_directories(test/fake)
# project headers
include_directories(src/PBlockIcons)
# gtest headers
include_directories(${gtest_SOURCE_DIR}/include)


add_executable(runTests
        test/fake/Arduino.cpp
        test/fake/MCUFRIEND_kbv.cpp
        test/fake/avr/pgmspace.cpp

        src/PBlockIcons/src/ui/TouchHandler.cpp
        src/PBlockIcons/src/ui/PBlocksUserInterface.cpp
        src/PBlockIcons/src/ui/DrawingGrid.cpp
        src/PBlockIcons/src/ui/ColorPalette.cpp
        src/PBlockIcons/src/ui/ExampleView.cpp
        src/PBlockIcons/src/ui/ColorPicker.cpp
        src/PBlockIcons/src/ui/Button.cpp
        src/PBlockIcons/src/ui/Tools.cpp
        src/PBlockIcons/src/ui/Toolbar.cpp
        src/PBlockIcons/src/screen/TFT.cpp
        src/PBlockIcons/src/screen/Font.cpp
        src/PBlockIcons/src/icons/ProgMemIcons.cpp
        src/PBlockIcons/src/storage/IconStorage.cpp
        src/PBlockIcons/src/storage/IconMem.cpp

        test/src/PBlocksDisplay/TestTouchRegion.cpp
        )

# link
add_subdirectory(test/lib/gtest-1.7.0)
target_link_libraries(runTests gtest_main)





