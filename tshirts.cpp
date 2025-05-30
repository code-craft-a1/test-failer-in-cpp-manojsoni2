#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms <= 42) {
        sizeName = 'M';
    } else {
        sizeName = 'L';
    }
    return sizeName;
}

void testSmallSize() {
    std::cout << "Testing small size...\n";
    assert(size(37) == 'S');
    assert(size(38) == 'S');
    std::cout << "Small size tests passed!\n";
}

void testMediumSize() {
    std::cout << "Testing medium size...\n";
    assert(size(39) == 'M');
    assert(size(40) == 'M');
    assert(size(42) == 'M');
    std::cout << "Medium size tests passed!\n";
}

void testLargeSize() {
    std::cout << "Testing large size...\n";
    assert(size(43) == 'L');
    assert(size(44) == 'L');
    std::cout << "Large size tests passed!\n";
}

void testEdgeCases() {
    std::cout << "Testing edge cases...\n";
    assert(size(0) == 'S');
    assert(size(100) == 'L');
    std::cout << "Edge cases tests passed!\n";
}

void testTshirtSize() {
    std::cout << "\nTshirt size test suite\n";
    testSmallSize();
    testMediumSize();
    testLargeSize();
    testEdgeCases();
    std::cout << "All t-shirt size tests passed!\n";
}
