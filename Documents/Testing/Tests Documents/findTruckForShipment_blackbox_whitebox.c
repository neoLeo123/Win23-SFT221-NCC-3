#include <stdio.h>
#include "mapping.h" // Include the header file with function prototypes and struct definitions
#include "diy.h"

void runwhiteboxTests() {
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
	printf("Result: %d\n\n", result1);

	// Test 2: Blue route
	struct Truck Truck2[NUMTRUCKS] = {
		{1000, 36, 'B'}, // Truck 0
		{1000, 36, 'G'},  // Truck 1
		{1000, 36, 'Y'}, // Truck 2
	};
	struct Shipment shipment2 = { 10, 1, {12,11} };
	printf("Test 2: Should return 0\n");
	int result2 = findTruckForShipment(&deliveryMap, Truck2, shipment2);
	printf("Result: %d\n\n", result2);

	// Test 3: Green route
	struct Truck Truck3[NUMTRUCKS] = {
	   {1000, 36, 'B'}, // Truck 0
	   {1000, 36, 'G'},  // Truck 1
	   {1000, 36, 'Y'}, // Truck 2
	};
	struct Shipment shipment3 = { 10, 1, {7, 18} };
	printf("Test 3: Should return 1\n");
	int result3 = findTruckForShipment(&deliveryMap, Truck3, shipment3);
	printf("Result: %d\n\n", result3);

	// Test 4: Same distance, different availability
	struct Truck Truck4[NUMTRUCKS] = {
	   {700, 35, 'B'}, {800, 35, 'G'}, {900, 35, 'Y'}
	};
	struct Shipment shipment4 = { 10, 1, {3, 2} };
	printf("Test 4: Should return 2\n");
	int result4 = findTruckForShipment(&deliveryMap, Truck4, shipment4);
	printf("Result: %d\n\n", result4);

	// Test 5: Same distance, different availability
	struct Truck Truck5[NUMTRUCKS] = {
	   {700, 35, 'B'}, {700, 34, 'G'}, {700, 33, 'Y'},
	};
	struct Shipment shipment5 = { 10, 1, {3, 2} };
	printf("Test 5: Should return 0\n");
	int result5 = findTruckForShipment(&deliveryMap, Truck5, shipment5);
	printf("Result: %d\n\n", result5);

	// Test 6: One truck not available
	struct Truck Truck6[NUMTRUCKS] = {
	   {400, 35, 'B'}, {700, 34, 'G'}, {700, 33, 'Y'},
	};
	struct Shipment shipment6 = { 500, 1, {14, 20} };
	printf("Test 6: Should return 1\n");
	int result6 = findTruckForShipment(&deliveryMap, Truck6, shipment6);
	printf("Result: %d\n\n", result6);

	printf("White box tests passed.\n\n");
};

// Test 7: All full
void runblackboxTests() {
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
	printf("Result: %d\n\n", result1);

	// Test 2: Enough size/not enough weight
	struct Truck Truck2[NUMTRUCKS] = {
	   {500, 3, 'B'}, // Truck 0
	   {100, 4, 'G'},  // Truck 1
	   {0, 3, 'Y'}, // Truck 2
	};
	struct Shipment shipment2 = { 500, 1, {13, 20} };
	printf("Test 2: Should return 0\n");
	int result2 = findTruckForShipment(&deliveryMap, Truck2, shipment2);
	printf("Result: %d\n\n", result2);

	// Test 3: Enough weight/not enough size
	struct Truck Truck3[NUMTRUCKS] = {
	   {700, 1, 'B'}, // Truck 0
	   {700, 0.5, 'G'},  // Truck 1
	   {0, 3, 'Y'}, // Truck 2
	};
	struct Shipment shipment3 = { 500, 1, {13, 20} };
	printf("Test 3: Should return 0\n");
	int result3 = findTruckForShipment(&deliveryMap, Truck3, shipment3);
	printf("Result: %d\n\n", result3);

	// Test 4: Enough weight/not enough size
	struct Truck Truck4[NUMTRUCKS] = {
	   {500, 0.25, 'B'}, // Truck 0
	   {500, 0.25, 'G'},  // Truck 1
	   {500, 0.25, 'Y'}, // Truck 2
	};
	struct Shipment shipment4 = { 500, 1, {13, 20} };
	printf("Test 4: Should return -1\n");
	int result4 = findTruckForShipment(&deliveryMap, Truck4, shipment4);
	printf("Result: %d\n\n", result4);

	// Test 5: Enough weight/not enough size
	struct Truck Truck5[NUMTRUCKS] = {
	   {100, 1, 'B'}, // Truck 0
	   {100, 1, 'G'},  // Truck 1
	   {100, 1, 'Y'}, // Truck 2
	};
	struct Shipment shipment5 = { 500, 1, {13, 20} };
	printf("Test 5: Should return -1\n");
	int result5 = findTruckForShipment(&deliveryMap, Truck5, shipment5);
	printf("Result: %d\n\n", result5);

	printf("Black box tests passed.\n");
};

int main() {
	runwhiteboxTests();
	runblackboxTests();
	return 0;
}