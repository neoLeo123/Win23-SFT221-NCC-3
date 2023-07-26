#include <stdio.h>
#include "mapping.h"

void testValidateAddressWhiteBox() {
    int pass = 1;
    // Test 1: Test with values in the valid range
    char r1 = 0, c1 = 0;
    printf("Test 1: Should return 1\n");
    int result1 = validateAddress(r1, c1);
    printf("Result: %d\n", result1);
    if (result1 == 1)
    {
        printf("Test 1 passed!\n\n");
    }
    else
    {
        printf("Test 1 failed!\n\n");
        pass = 0;
    }

    // Test 2: Test with values in the valid range
    char r2 = 24, c2 = 24;
    printf("Test 2: Should return 1\n");
    int result2 = validateAddress(r2, c2);
    printf("Result: %d\n", result2);
    if (result2 == 1)
    {
        printf("Test 2 passed!\n\n");
    }
    else
    {
        printf("Test 2 failed!\n\n");
        pass = 0;
    }


    // Test 3: Test with values in the valid range
    char r3 = 14, c3 = 12;
    printf("Test 3: Should return 1\n");
    int result3 = validateAddress(r3, c3);
    printf("Result: %d\n", result3);
    if (result3 == 1)
    {
        printf("Test 3 passed!\n\n");
    }
    else
    {
        printf("Test 3 failed!\n\n");
        pass = 0;
    }

    // Test 4: Test with values outside the valid range
    char r4 = 25, c4 = 0;
    printf("Test 4: Should return 0\n");
    int result4 = validateAddress(r4, c4);
    printf("Result: %d\n", result4);
    if (result4 == 0)
    {
        printf("Test 4 passed!\n\n");
    }
    else
    {
        printf("Test 4 failed!\n\n");
        pass = 0;
    }

    // Test 5: Test with values outside the valid range
    char r5 = -1, c5 = 0;
    printf("Test 5: Should return 0\n");
    int result5 = validateAddress(r5, c5);
    printf("Result: %d\n", result5);
    if (result5 == 0)
    {
        printf("Test 5 passed!\n\n");
    }
    else
    {
        printf("Test 5 failed!\n\n");
        pass = 0;
    }

    // Test 6: Test with values outside the valid range
    char r6 = 0, c6 = 25;
    printf("Test 6: Should return 0\n");
    int result6 = validateAddress(r6, c6);
    printf("Result: %d\n", result6);
    if (result6 == 0)
    {
        printf("Test 6 passed!\n\n");
    }
    else
    {
        printf("Test 6 failed!\n\n");
        pass = 0;
    }

    if (pass)
    {
        printf("White box tests passed.\n\n");

    }
    else
    {
        printf("White box tests failed.\n\n");
    }
}

// Black box
void test_validateAddressBlackBox() {
    int pass = 1;
    // Test 1: Empty string
    char r1 = NULL, c1 = NULL;
    printf("Test 1: Should return 0\n");
    int result1 = validateAddress(r1, c1);
    printf("Result: %d\n", result1);
    if (result1 == 0)
    {
        printf("Test 1 passed!\n\n");
    }
    else
    {
        printf("Test 1 failed!\n\n");
        pass = 0;
    }

    // Test 2: Space string
    char r2 = ' ', c2 = ' ';
    printf("Test 2: Should return 0\n");
    int result2 = validateAddress(r2, c2);
    printf("Result: %d\n", result2);
    if (result2 == 0)
    {
        printf("Test 2 passed!\n\n");
    }
    else
    {
        printf("Test 2 failed!\n\n");
        pass = 0;
    }

    // Test 3: Special character
    char r3 = '@', c3 = '@';
    printf("Test 3: Should return 0\n");
    int result3 = validateAddress(r3, c3);
    printf("Result: %d\n", result3);
    if (result3 == 0)
    {
        printf("Test 3 passed!\n\n");
    }
    else
    {
        printf("Test 3 failed!\n\n");
        pass = 0;
    }

    // Test 4: Alphabetic character
    char r4 = 'a', c4 = 'a';
    printf("Test 4: Should return 0\n");
    int result4 = validateAddress(r4, c4);
    printf("Result: %d\n", result4);
    if (result4 == 0)
    {
        printf("Test 4 passed!\n\n");
    }
    else
    {
        printf("Test 4 failed!\n\n");
        pass = 0;
    }
    
    // Test 5: Invalid character
    char r5 = '1', c5 = 'Z';
    printf("Test 5: Should return 0\n");
    int result5 = validateAddress(r5, c5);
    printf("Result: %d\n", result5);
    if (result5 == 0)
    {
        printf("Test 5 passed!\n\n");
    }
    else
    {
        printf("Test 5 failed!\n\n");
        pass = 0;
    }

    // Test 6: Invalid character
    char r6 = '2', c6 = '2';
    printf("Test 6: Should return 0\n");
    int result6 = validateAddress(r6, c6);
    printf("Result: %d\n", result6);
    if (result5 == 0)
    {
        printf("Test 6 passed!\n\n");
    }
    else
    {
        printf("Test 6 failed!\n\n");
        pass = 0;
    }
        
    if (pass)
    {
        printf("Black box tests passed.\n\n");

    }
    else
    {
        printf("Black box tests failed.\n\n");
    }

}

int main() {
    testValidateAddressWhiteBox();
    test_validateAddressBlackBox();
    return 0;
}
