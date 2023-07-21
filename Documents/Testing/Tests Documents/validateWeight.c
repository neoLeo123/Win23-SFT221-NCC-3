#include <assert.h>
#include <stdio.h>

void test_validateWeight() {
    // Test with weight within the valid range
    assert(validateWeight(500.0) == true);

    // Test with weight at the lower limit
    assert(validateWeight(1.0) == true);

    // Test with weight at the upper limit
    assert(validateWeight(1000.0) == true);

    // Test with weight below the valid range
    assert(validateWeight(0.99) == false);

    // Test with weight above the valid range
    assert(validateWeight(1000.01) == false);

    printf("All tests passed.\n");
}

int main() {
    test_validateWeight();
    return 0;
}
