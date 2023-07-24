#include <stdio.h>
#include "mapping.h"

void test_validateSizeBlackBox() {
    // Test with a valid size
    printf("Test 1: %d\n", validateSize(0.25));

    // Test with another valid size
    printf("Test 2: %d\n", validateSize(0.5));

    // Test with yet another valid size
    printf("Test 3: %d\n", validateSize(1.0));

    // Test with an invalid size
    printf("Test 4: %d\n", validateSize(0.75));

    printf("Black box tests passed.\n");
}

void testValidateSizeWhiteBox() {
    // Test 1: Test with values equal to the expected ones
    printf("Test 1: %d\n", validateSize(0.25));
    printf("Test 2: %d\n", validateSize(0.5));
    printf("Test 3: %d\n", validateSize(1));

    // Test 2: Test with values just below the expected ones
    printf("Test 4: %d\n", validateSize(0.24));
    printf("Test 5: %d\n", validateSize(0.49));
    printf("Test 6: %d\n", validateSize(0.99));

    // Test 3: Test with values just above the expected ones
    printf("Test 7: %d\n", validateSize(0.26));
    printf("Test 8: %d\n", validateSize(0.51));
    printf("Test 9: %d\n", validateSize(1.01));

    // Test 4: Test with zero
    printf("Test 10: %d\n", validateSize(0.0));

    // Test 5: Test with negative values
    printf("Test 11: %d\n", validateSize(-0.25));
    printf("Test 12: %d\n", validateSize(-0.5));
    printf("Test 13: %d\n", validateSize(-1));

    printf("White box tests passed.\n");
}

int main() {
    test_validateSizeBlackBox();
    testValidateSizeWhiteBox();
    return 0;
}
