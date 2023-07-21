#include <assert.h>
#include <stdio.h>

void test_validateAddress() {
    // Test with valid coordinates
    assert(validateAddress(10, 'L') == true);

    // Test with coordinates at the lower limit
    assert(validateAddress(1, 'A') == true);

    // Test with coordinates at the upper limit
    assert(validateAddress(25, 'Y') == true);

    // Test with coordinates below the valid range
    assert(validateAddress(0, 'A') == false);
    assert(validateAddress(10, 'Z') == false);

    // Test with coordinates above the valid range
    assert(validateAddress(26, 'A') == false);
    assert(validateAddress(10, 'Z') == false);

    printf("All tests passed.\n");
}

int main() {
    test_validateAddress();
    return 0;
}
