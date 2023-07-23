#include <stdio.h>


void testValidateAddressWhiteBox() {
    // Test 1: Test with values in the valid range
    printf("Test 1: %d\n", validateAddress(1, 'A'));
    printf("Test 2: %d\n", validateAddress(25, 'Z'));
    printf("Test 3: %d\n", validateAddress(15, 'M'));

    // Test 2: Test with y values outside the valid range
    printf("Test 4: %d\n", validateAddress(0, 'A'));
    printf("Test 5: %d\n", validateAddress(26, 'A'));
    printf("Test 6: %d\n", validateAddress(-1, 'A'));

    // Test 3: Test with x values outside the valid range
    printf("Test 7: %d\n", validateAddress(1, 'a'));
    printf("Test 8: %d\n", validateAddress(1, '!'));
    printf("Test 9: %d\n", validateAddress(1, 'Z' + 1));

    // Test 4: Test with y and x values outside the valid range
    printf("Test 10: %d\n", validateAddress(-1, 'a'));
    printf("Test 11: %d\n", validateAddress(30, '!'));
    printf("Test 12: %d\n", validateAddress(0, 'Z' + 1));

    printf("White box tests passed.\n");
}

// Black box
void test_validateAddressBlackBox() {
    // Test with valid coordinates
    printf("Test 13: %d\n", validateAddress(10, 'L'));

    // Test with coordinates at the lower limit
    printf("Test 14: %d\n", validateAddress(1, 'A'));

    // Test with coordinates at the upper limit
    printf("Test 15: %d\n", validateAddress(25, 'Y'));

    // Test with coordinates below the valid range
    printf("Test 16: %d\n", validateAddress(0, 'A'));
    printf("Test 17: %d\n", validateAddress(10, 'Z'));

    // Test with coordinates above the valid range
    printf("Test 18: %d\n", validateAddress(26, 'A'));
    printf("Test 19: %d\n", validateAddress(10, 'Z'));

    printf("Black box tests passed.\n");
}

int main() {
    testValidateAddressWhiteBox();
    test_validateAddressBlackBox();
    return 0;
}
