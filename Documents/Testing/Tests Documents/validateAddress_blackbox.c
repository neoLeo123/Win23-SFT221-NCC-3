#include <assert.h>
#include <stdio.h>

void test_validateAddress() {
    // Test with valid coordinates
    assert(validateAddress(10, 'L') == 1);

    // Test with coordinates at the lower limit
    assert(validateAddress(1, 'A') == 1);

    // Test with coordinates at the upper limit
    assert(validateAddress(25, 'Y') == 1);

    // Test with coordinates below the valid range
    assert(validateAddress(0, 'A') == 0);
    assert(validateAddress(10, 'Z') == 0);

    // Test with coordinates above the valid range
    assert(validateAddress(26, 'A') == 0);
    assert(validateAddress(10, 'Z') == 0);

    printf("All tests passed.\n");
}

int main() {
    test_validateAddress();
    return 0;
}
