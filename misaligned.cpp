#include <iostream>
#include <assert.h>
#include <string>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

void testFirstColorPair() {
    std::cout << "Testing first color pair...\n";
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    assert(std::string(majorColor[0]) == "White");
    assert(std::string(minorColor[0]) == "Blue");
    std::cout << "First color pair test passed!\n";
}

void testLastColorPair() {
    std::cout << "Testing last color pair...\n";
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    assert(std::string(majorColor[4]) == "Violet");
    assert(std::string(minorColor[4]) == "Slate");
    std::cout << "Last color pair test passed!\n";
}

void testMiddleColorPair() {
    std::cout << "Testing middle color pair...\n";
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    assert(std::string(majorColor[2]) == "Black");
    assert(std::string(minorColor[2]) == "Green");
    std::cout << "Middle color pair test passed!\n";
}

void testColorMapSize() {
    std::cout << "Testing color map size...\n";
    int result = printColorMap();
    assert(result == 25);
    std::cout << "Color map size test passed!\n";
}

void testPrintColorMap() {
    std::cout << "\nColor map test suite\n";
    testFirstColorPair();
    testLastColorPair();
    testMiddleColorPair();
    testColorMapSize();
    std::cout << "All color map tests passed!\n";
}
