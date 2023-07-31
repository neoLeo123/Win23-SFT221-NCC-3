#include <stdio.h>
#include "mapping.h" // Include the header file with function prototypes and struct definitions
#include "diy.h"

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
	struct Shipment shipment1;
	double weight = 100, size = 1;
	int yaxis = 22; int xaxis = 1;
	if (validateWeight(weight)==1 && validateSize(size)==1 && validateAddress(yaxis,xaxis)==1)
	{
		shipment1.weight = weight;
		shipment1.size = size;
		shipment1.destination.row = yaxis-1;
		shipment1.destination.col = (int)xaxis - 65;
	}
	int result1 = findTruckForShipment(&deliveryMap, Truck1, shipment1);
	printf("Test 1 should return 2");
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

	
	struct Truck Truck2[NUMTRUCKS] = {
		{1000, 36, 'B'}, // Truck 0
		{1000, 36, 'G'},  // Truck 1
		{1000, 36, 'Y'}, // Truck 2
	};
	struct Shipment shipment2;
	 weight = 20, size = 1;
	 yaxis = 12;  xaxis = 11;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment2.weight = weight;
		shipment2.size = size;
		shipment2.destination.row = yaxis - 1;
		shipment2.destination.col = (int)xaxis - 65;
	}
	int result2 = findTruckForShipment(&deliveryMap, Truck2, shipment2);
	printf("Test 2 should return 0");

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
	struct Shipment shipment3;
	double weight = 30, size = 1;
	int yaxis = 7;  xaxis = 18;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis,xaxis) == 1)
	{
		shipment3.weight = weight;
		shipment3.size = size;
		shipment3.destination.row = yaxis - 1;
		shipment3.destination.col = (int)xaxis - 65;
	}
	int result3 = findTruckForShipment(&deliveryMap, Truck3, shipment3);
	printf("Test 3 should return 1");

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
	   {500, 35, 'B'}, {700, 35, 'G'}, {600, 35, 'Y'}
	};
	struct Shipment shipment4;
	double weight = 200, size = 1.0;
	int yaxis = 3;  xaxis = 2;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment4.weight = weight;
		shipment4.size = size;
		shipment4.destination.row = yaxis - 1;
		shipment4.destination.col = (int)xaxis - 65;
	}
	int result4 = findTruckForShipment(&deliveryMap, Truck4, shipment4);
	printf("Test 4 should return 2");

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
	   {700, 35, 'B'}, {800, 34, 'G'}, {900, 33, 'Y'},
	};
	struct Shipment shipment5;
	double weight = 100, size = 1.0;
	int yaxis = 3;  xaxis = 2;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment5.weight = weight;
		shipment5.size = size;
		shipment5.destination.row = yaxis - 1;
		shipment5.destination.col = (int)xaxis - 65;
	}
	printf("Test 5 should return 0");
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
	struct Shipment shipment6;
	double weight = 400, size = 1.0;
	int yaxis = 14;  xaxis = 20;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment6.weight = weight;
		shipment6.size = size;
		shipment6.destination.row = yaxis - 1;
		shipment6.destination.col = (int)xaxis - 65;
	}
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
	{0, 5, 'B'}, // Truck 0
	{0, 6, 'G'},  // Truck 1
	{0, 4, 'Y'}, // Truck 2
	};
	struct Shipment shipment1;
	double weight = 500, size = 1.0;
	int yaxis = 14;  int xaxis = 20;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment1.weight = weight;
		shipment1.size = size;
		shipment1.destination.row = yaxis - 1;
		shipment1.destination.col = (int)xaxis - 65;
	}
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
	struct Shipment shipment2;
	double weight = 500, size = 1.0;
	int yaxis = 13;   xaxis = 20;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment2.weight = weight;
		shipment2.size = size;
		shipment2.destination.row = yaxis - 1;
		shipment2.destination.col = (int)xaxis - 65;
	}
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
	struct Truck Truck4[NUMTRUCKS] = {
	   {500, 0.25, 'B'}, // Truck 0
	   {500, 0.25, 'G'},  // Truck 1
	   {500, 0.25, 'Y'}, // Truck 2
	};
	struct Shipment shipment4;
	double weight =500, size = 1;
	int yaxis = 13;  xaxis = 20;
	if (validateWeight(weight) == 1 && validateSize(size) == 1 && validateAddress(yaxis, xaxis) == 1)
	{
		shipment4.weight = weight;
		shipment4.size = size;
		shipment4.destination.row = yaxis - 1;
		shipment4.destination.col = (int)xaxis - 65;
	}
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
	runwhiteboxTests();
	runblackboxTests();
	return 0;
}
