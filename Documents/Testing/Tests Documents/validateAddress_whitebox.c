#include <assert.h>

void testValidateAddress() {
    // Test 1: Test with values in the valid range
    assert(validateAddress(1, 'A') == 1);
    assert(validateAddress(25, 'Z') == 1);
    assert(validateAddress(15, 'M') == 1);

    // Test 2: Test with y values outside the valid range
    assert(validateAddress(0, 'A') == 0);
    assert(validateAddress(26, 'A') == 0);
    assert(validateAddress(-1, 'A') == 0);

    // Test 3: Test with x values outside the valid range
    assert(validateAddress(1, 'a') == 0);
    assert(validateAddress(1, '!') == 0);
    assert(validateAddress(1, 'Z' + 1) == 0);

    // Test 4: Test with y and x values outside the valid range
    assert(validateAddress(-1, 'a') == 0);
    assert(validateAddress(30, '!') == 0);
    assert(validateAddress(0, 'Z' + 1) == 0);

    printf("All tests passed.\n");
}

int main() {
    testValidateAddress();
    return 0;
}
