#include <assert.h>
#include <stdio.h>

void test_validateSize() {
    // Test with a valid size
    assert(validateSize(0.25) == true);

    // Test with another valid size
    assert(validateSize(0.5) == true);

    // Test with yet another valid size
    assert(validateSize(1.0) == true);

    // Test with an invalid size
    assert(validateSize(0.75) == false);

    printf("All tests passed.\n");
}

int main() {
    test_validateSize();
    return 0;
}
