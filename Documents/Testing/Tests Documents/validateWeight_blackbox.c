#include <assert.h>
#include <stdio.h>

void test_validateWeight() {
    // Test with weight within the valid range
    assert(validateWeight(500) == 1);

    // Test with weight at the lower limit
    assert(validateWeight(1) == 1);

    // Test with weight at the upper limit
    assert(validateWeight(1000) == 1);

    // Test with weight below the valid range
    assert(validateWeight(0.99) == 0);

    // Test with weight above the valid range
    assert(validateWeight(1000) == 0);

    printf("All tests passed.\n");
}

int main() {
    test_validateWeight();
    return 0;
}
