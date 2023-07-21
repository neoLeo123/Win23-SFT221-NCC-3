#include <assert.h>

void testValidateWeight() {
    // Test 1: Test with a value in valid range (edge case)
    assert(validateWeight(1.0) == 1);
    assert(validateWeight(1000.0) == 1);

    // Test 2: Test with a value below the valid range
    assert(validateWeight(-1.0) == 0);

    // Test 3: Test with a value above the valid range
    assert(validateWeight(1000.01) == 0);
    assert(validateWeight(2000.0) == 0);

    // Test 4: Test with zero
    assert(validateWeight(0.0) == 0);
    
    // Test 5: Test with negative values
    assert(validateWeight(-100.0) == 0);
    assert(validateWeight(-1000.0) == 0);
    
    printf("All tests passed.\n");
}

int main() {
    testValidateWeight();
    return 0;
}
