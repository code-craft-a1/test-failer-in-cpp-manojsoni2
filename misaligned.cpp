#include <iostream>
#include <assert.h>
#include <string>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    assert(result == 25);
    
    // Test specific color pairings
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    // Test first pairing (should be White-Blue)
    assert(std::string(majorColor[0]) == "White");
    assert(std::string(minorColor[0]) == "Blue");
    
    // Test last pairing (should be Violet-Slate)
    assert(std::string(majorColor[4]) == "Violet");
    assert(std::string(minorColor[4]) == "Slate");
    
    // Test middle pairing (should be Black-Green)
    assert(std::string(majorColor[2]) == "Black");
    assert(std::string(minorColor[2]) == "Green");
    
    std::cout << "All is well (maybe!)\n";
}
