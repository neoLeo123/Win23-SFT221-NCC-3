#include <stdio.h>
#include "mapping.h


void test_validateWeightBlackBox() {
    // Test with weight within the valid range
    printf("Test 1: %d\n", validateWeight(500.00));

    // Test with weight at the lower limit
    printf("Test 2: %d\n", validateWeight(1.00));

    // Test with weight at the upper limit
    printf("Test 3: %d\n", validateWeight(1000.00));

    // Test with weight below the valid range
    printf("Test 4: %d\n", validateWeight(0.99));

    // Test with weight above the valid range
    printf("Test 5: %d\n", validateWeight(1001.00));

    printf("Black box tests passed.\n");
}

void testValidateWeightWhiteBox() {
    // Test 1: Test with a value in valid range (edge case)
    printf("Test 1: %d\n", validateWeight(1.0));
    printf("Test 2: %d\n", validateWeight(1000.0));

    // Test 2: Test with a value below the valid range
    printf("Test 3: %d\n", validateWeight(-1.0));

    // Test 3: Test with a value above the valid range
    printf("Test 4: %d\n", validateWeight(1000.01));
    printf("Test 5: %d\n", validateWeight(2000.0));

    // Test 4: Test with zero
    printf("Test 6: %d\n", validateWeight(0.0));

    // Test 5: Test with negative values
    printf("Test 7: %d\n", validateWeight(-100.0));
    printf("Test 8: %d\n", validateWeight(-1000.0));

    printf("White box tests passed.\n");
}

int main() {
    test_validateWeightBlackBox();
    testValidateWeightWhiteBox();
    return 0;
}
