#include <stdio.h>
#include "mapping.h"

void test_validateSizeBlackBox() {
    // Test with a valid size
    int pass = 1;
    // Test with a valid size
    double size1 = 0.25;
    printf("Test 1: Should return 1\n");
    int result1 = validateSize(size1);
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

    // Test with another valid size
    
    double size2 = 0.5;
    printf("Test 2: Should return 1\n");
    int result2 = validateSize(size2);
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
    // Test with yet another valid size
    printf("Test 3: %d\n", validateSize(1.0));
    double size3 = 1.0;
    printf("Test 3: Should return 1\n");
    int result3 = validateSize(size3);
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
    // Test with an invalid size
    
    double size4 = 0.75;
    printf("Test 4: Should return 0\n");
    int result4 = validateSize(size4);
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
    
    if (pass)
    {
        printf("Black box tests passed.\n\n");

    }
    else
    {
        printf("Black box tests failed.\n\n");
    }
}

void testValidateSizeWhiteBox() {
    int pass = 1;
    // Test 1: Test with values just below the expected ones
    double size1= 0.24;
    printf("Test 1: Should return 0\n");
    int result1 = validateSize(size1);
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
    
    double size2 = 0.49;
    printf("Test 2: Should return 0\n");
    int result2 = validateSize(size2);
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
    
    double size3 = 0.99;
    printf("Test 3: Should return 0\n");
    int result3 = validateSize(size3);
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
 
    // Test 4: Test with zero
    double size4 = 0;
    printf("Test 4: Should return 0\n");
    int result4 = validateSize(size4);
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
    // Test 5: Test with negative values
    double size5 = -0.25;
    printf("Test 5: Should return 0\n");
    int result5 = validateSize(size5);
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
    
    if (pass)
    {
        printf("White box tests passed.\n\n");

    }
    else
    {
        printf("White box tests failed.\n\n");
    }

}

int main() {
    test_validateSizeBlackBox();
    testValidateSizeWhiteBox();
    return 0;
}
