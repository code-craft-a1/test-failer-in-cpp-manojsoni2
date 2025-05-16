#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    // Test regular cases
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    
    // Test boundary cases
    assert(size(38) == 'M');  // Should be M but returns '\0'
    assert(size(42) == 'L');  // Should be L but returns '\0'
    
    // Test edge cases
    assert(size(0) == 'S');   // Very small size
    assert(size(100) == 'L'); // Very large size
    
    std::cout << "All is well (maybe!)\n";
}
