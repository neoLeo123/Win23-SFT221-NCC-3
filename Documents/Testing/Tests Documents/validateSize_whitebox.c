#include <assert.h>

void testValidateSize() {
    // Test 1: Test with values equal to the expected ones
    assert(validateSize(0.25) == 1);
    assert(validateSize(0.5) == 1);
    assert(validateSize(1) == 1);

    // Test 2: Test with values just below the expected ones
    assert(validateSize(0.24) == 0);
    assert(validateSize(0.49) == 0);
    assert(validateSize(0.99) == 0);

    // Test 3: Test with values just above the expected ones
    assert(validateSize(0.26) == 0);
    assert(validateSize(0.51) == 0);
    assert(validateSize(1.01) == 0);

    // Test 4: Test with zero
    assert(validateSize(0.0) == 0);

    // Test 5: Test with negative values
    assert(validateSize(-0.25) == 0);
    assert(validateSize(-0.5) == 0);
    assert(validateSize(-1) == 0);

    printf("All tests passed.\n");
}

int main() {
    testValidateSize();
    return 0;
}
