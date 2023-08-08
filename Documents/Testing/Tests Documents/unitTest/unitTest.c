#include <stdio.h>
#include "mapping.h"
#include "diy.h"

void testValidateAddressWhiteBox() {
    int pass = 1;
    // Test 1: Test with values in the valid range
    int r1 = 1;
    char c1 = 'A';
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
    int r2 = 25;
    char c2 = 'Y';
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
    int r3 = 15;
    char c3 = 'M';
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
    int r4 = 26;
    char c4 = 'A';
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
    int r5 = -1;
    char c5 = 'A';
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
    int r6 = 1;
    char c6 = 'Z';
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
    int r1 = NULL;
    char c1 = NULL;
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
    int r2 = 0;
    char c2 = ' ';
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
    int r3 = 0;
    char c3 = '@';
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
    int r4 = 'a';
    char c4 = '0';
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
    int r5 = 1;
    char c5 = 'Z';
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
    int r6 = 2;
    char c6 = '2';
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
    double size1 = 0.24;
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

void runwhiteboxTests() {

    int pass = 1;
    // Create some test data for Trucks and shipment

    // Create a map (you can initialize it as needed)
    struct Map deliveryMap;
    // populateMap(&deliveryMap); // Uncomment and implement if necessary

    // Test 1: Yellow route
    struct Truck Truck1[NUMTRUCKS] = {
        {1000, 36, 'B'}, // Truck 0
        {1000, 36, 'G'},  // Truck 1
        {1000, 36, 'Y'}, // Truck 2
    };
    struct Shipment shipment1 = { 10, 1, {22, 1} };
    printf("Test 1: Should return 2\n");
    int result1 = findTruckForShipment(&deliveryMap, Truck1, shipment1);
    printf("Result: %d\n", result1);
    if (result1 == 2)
    {
        printf("Test 1 passed!\n\n");
    }
    else
    {
        printf("Test 1 failed!\n\n");
        pass = 0;
    }

    // Test 2: Blue route
    struct Truck Truck2[NUMTRUCKS] = {
        {1000, 36, 'B'}, // Truck 0
        {1000, 36, 'G'},  // Truck 1
        {1000, 36, 'Y'}, // Truck 2
    };
    struct Shipment shipment2 = { 10, 1, {12,11} };
    printf("Test 2: Should return 0\n");
    int result2 = findTruckForShipment(&deliveryMap, Truck2, shipment2);
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

    // Test 3: Green route
    struct Truck Truck3[NUMTRUCKS] = {
       {1000, 36, 'B'}, // Truck 0
       {1000, 36, 'G'},  // Truck 1
       {1000, 36, 'Y'}, // Truck 2
    };
    struct Shipment shipment3 = { 10, 1, {7, 18} };
    printf("Test 3: Should return 1\n");
    int result3 = findTruckForShipment(&deliveryMap, Truck3, shipment3);
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

    // Test 4: Same distance, different availability
    struct Truck Truck4[NUMTRUCKS] = {
       {700, 35, 'B'}, {800, 35, 'G'}, {900, 35, 'Y'}
    };
    struct Shipment shipment4 = { 10, 1, {3, 2} };
    printf("Test 4: Should return 2\n");
    int result4 = findTruckForShipment(&deliveryMap, Truck4, shipment4);
    printf("Result: %d\n", result4);

    if (result4 == 2)
    {
        printf("Test 4 passed!\n\n");
    }
    else
    {
        printf("Test 4 failed!\n\n");
        pass = 0;
    }

    // Test 5: Same distance, different availability
    struct Truck Truck5[NUMTRUCKS] = {
       {700, 35, 'B'}, {700, 34, 'G'}, {700, 33, 'Y'},
    };
    struct Shipment shipment5 = { 10, 1, {3, 2} };
    printf("Test 5: Should return 0\n");
    int result5 = findTruckForShipment(&deliveryMap, Truck5, shipment5);
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

    // Test 6: One truck not available
    struct Truck Truck6[NUMTRUCKS] = {
       {400, 35, 'B'}, {700, 34, 'G'}, {700, 33, 'Y'},
    };
    struct Shipment shipment6 = { 500, 1, {14, 20} };
    printf("Test 6: Should return 1\n");
    int result6 = findTruckForShipment(&deliveryMap, Truck6, shipment6);
    printf("Result: %d\n", result6);

    if (result6 == 1)
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
};


void runblackboxTests() {

    int pass = 1;

    struct Map deliveryMap;

    //Test 1: All full
    struct Truck Truck1[NUMTRUCKS] = {
    {0, 3, 'B'}, // Truck 0
    {0, 4, 'G'},  // Truck 1
    {0, 3, 'Y'}, // Truck 2
    };
    struct Shipment shipment1 = { 500, 1, {14, 20} };
    printf("Test 1: Should return -1\n");
    int result1 = findTruckForShipment(&deliveryMap, Truck1, shipment1);
    printf("Result: %d\n", result1);

    if (result1 == -1)
    {
        printf("Test 1 passed!\n\n");
    }
    else
    {
        printf("Test 1 failed!\n\n");
        pass = 0;
    }

    // Test 2: Enough size/not enough weight
    struct Truck Truck2[NUMTRUCKS] = {
       {500, 3, 'B'}, // Truck 0
       {100, 4, 'G'},  // Truck 1
       {0, 3, 'Y'}, // Truck 2
    };
    struct Shipment shipment2 = { 500, 1, {13, 20} };
    printf("Test 2: Should return 0\n");
    int result2 = findTruckForShipment(&deliveryMap, Truck2, shipment2);
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



    // Test 3: Enough weight/not enough size
    struct Truck Truck3[NUMTRUCKS] = {
       {700, 1, 'B'}, // Truck 0
       {700, 0.5, 'G'},  // Truck 1
       {0, 3, 'Y'}, // Truck 2
    };
    struct Shipment shipment3 = { 500, 1, {13, 20} };
    printf("Test 3: Should return 0\n");
    int result3 = findTruckForShipment(&deliveryMap, Truck3, shipment3);
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

    // Test 4: Enough weight/not enough size
    struct Truck Truck4[NUMTRUCKS] = {
       {500, 0.25, 'B'}, // Truck 0
       {500, 0.25, 'G'},  // Truck 1
       {500, 0.25, 'Y'}, // Truck 2
    };
    struct Shipment shipment4 = { 500, 1, {13, 20} };
    printf("Test 4: Should return -1\n");
    int result4 = findTruckForShipment(&deliveryMap, Truck4, shipment4);
    printf("Result: %d\n", result4);

    if (result4 == -1)
    {
        printf("Test 4 passed!\n\n");
    }
    else
    {
        printf("Test 4 failed!\n\n");
        pass = 0;
    }

    // Test 5: Enough weight/not enough size
    struct Truck Truck5[NUMTRUCKS] = {
       {100, 1, 'B'}, // Truck 0
       {100, 1, 'G'},  // Truck 1
       {100, 1, 'Y'}, // Truck 2
    };
    struct Shipment shipment5 = { 500, 1, {13, 20} };
    printf("Test 5: Should return -1\n");
    int result5 = findTruckForShipment(&deliveryMap, Truck5, shipment5);
    printf("Result: %d\n", result5);

    if (result5 == -1)
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
        printf("Black box tests passed.\n\n");

    }
    else
    {
        printf("Black box tests failed.\n\n");
    }

};


int main() {
    testValidateAddressWhiteBox();
    test_validateAddressBlackBox();
    test_validateSizeBlackBox();
    testValidateSizeWhiteBox();
    test_validateWeightWhiteBox();
    test_ValidateWeightBlackBox();
    runwhiteboxTests();
    runblackboxTests();
    return 0;
}