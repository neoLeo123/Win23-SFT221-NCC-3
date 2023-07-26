#include <stdio.h>
#include "mapping.h"


void test_validateWeightWhiteBox() {
    int pass = 1;
    // Test 1: weight within the valid range
    double weight1 = 500.00;
    printf("Test 1: Should return 1\n");
    int result1 = validateWeight(weight1);
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

    // Test 2: weight at the lower limit
    double weight2 = 1.00;
    printf("Test 2: Should return 1\n");
    int result2 = validateWeight(weight2);
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


    // Test 3: weight at the upper limit
    double weight3 = 1000.00;
    printf("Test 3: Should return 1\n");
    int result3 = validateWeight(weight3);
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

    // Test 4: weight below the valid range
    double weight4 = 0.99;
    printf("Test 4: Should return 0\n");
    int result4 = validateWeight(weight4);
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

    // Test 5: weight above the valid range
    double weight5 = 1001.00;
    printf("Test 5: Should return 0\n");
    int result5 = validateWeight(weight5);
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

void test_ValidateWeightBlackBox() {
    int pass = 1;
    // Test 1: test with zero
    double weight1 = 0.0;
    printf("Test 1: Should return 0\n");
    int result1 = validateWeight(weight1);
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


    // Test 2: Test with negative
    double weight2 = -0.01;
    printf("Test 2: Should return 0\n");
    int result2 = validateWeight(weight2);
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


    // Test 3: Test with negative values
    double weight3 = -1000.00;
    printf("Test 3: Should return 0\n");
    int result3 = validateWeight(weight3);
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
    
    test_validateWeightWhiteBox();
    test_ValidateWeightBlackBox();
    return 0;
}
