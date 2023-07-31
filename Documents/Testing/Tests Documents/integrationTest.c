#include <stdio.h>
#include "mapping.h" // Include the header file with function prototypes and struct definitions
#include "diy.h"

void runIntegrationTests() {

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
	double weight1 = 10, size1 = 1;
	int yaxis1 = 22; char xaxis1 = 'B';
	if (validateWeight(weight1) == 1 && validateSize(size1) == 1 && validateAddress(yaxis1, xaxis1) == 1)
	{
		shipment1.weight = weight1;
		shipment1.size = size1;
		shipment1.dest.row = yaxis1 - 1;
		shipment1.dest.col = (int)xaxis1 - 65;
	}
	int result1 = findTruckForShipment(&deliveryMap, Truck1, shipment1);
	printf("Test 1 should return 2\n");
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

	//Test 2: Blue route
	struct Truck Truck2[NUMTRUCKS] = {
		{1000, 36, 'B'}, // Truck 0
		{1000, 36, 'G'},  // Truck 1
		{1000, 36, 'Y'}, // Truck 2
	};
	struct Shipment shipment2;
	double weight2 = 10, size2 = 1;
	int yaxis2 = 12;  char xaxis2 = 'L';
	if (validateWeight(weight2) == 1 && validateSize(size2) == 1 && validateAddress(yaxis2, xaxis2) == 1)
	{
		shipment2.weight = weight2;
		shipment2.size = size2;
		shipment2.dest.row = yaxis2 - 1;
		shipment2.dest.col = (int)xaxis2 - 65;
	}
	int result2 = findTruckForShipment(&deliveryMap, Truck2, shipment2);
	printf("Test 2 should return 0\n");

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
	double weight3 = 30, size3 = 1;
	int yaxis3 = 7;  char xaxis3 = 'S';
	if (validateWeight(weight3) == 1 && validateSize(size3) == 1 && validateAddress(yaxis3, xaxis3) == 1)
	{
		shipment3.weight = weight3;
		shipment3.size = size3;
		shipment3.dest.row = yaxis3 - 1;
		shipment3.dest.col = (int)xaxis3 - 65;
	}
	int result3 = findTruckForShipment(&deliveryMap, Truck3, shipment3);
	printf("Test 3 should return 1\n");

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
	struct Shipment shipment4;
	double weight4 = 10, size4 = 1;
	int yaxis4 = 3;  char xaxis4 = 'C';
	if (validateWeight(weight4) == 1 && validateSize(size4) == 1 && validateAddress(yaxis4, xaxis4) == 1)
	{
		shipment4.weight = weight4;
		shipment4.size = size4;
		shipment4.dest.row = yaxis4 - 1;
		shipment4.dest.col = (int)xaxis4 - 65;
	}
	int result4 = findTruckForShipment(&deliveryMap, Truck4, shipment4);
	printf("Test 4 should return 2\n");

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
	struct Shipment shipment5;
	double weight5 = 10, size5 = 1;
	int yaxis5 = 3;  char xaxis5 = 'C';
	if (validateWeight(weight5) == 1 && validateSize(size5) == 1 && validateAddress(yaxis5, xaxis5) == 1)
	{
		shipment5.weight = weight5;
		shipment5.size = size5;
		shipment5.dest.row = yaxis5 - 1;
		shipment5.dest.col = (int)xaxis5 - 65;
	}
	printf("Test 5 should return 0\n");
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
	double weight6 = 400, size6 = 1.0;
	int yaxis6 = 14;  char xaxis6 = 'U';
	if (validateWeight(weight6) == 1 && validateSize(size6) == 1 && validateAddress(yaxis6, xaxis6) == 1)
	{
		shipment6.weight = weight6;
		shipment6.size = size6;
		shipment6.dest.row = yaxis6 - 1;
		shipment6.dest.col = (int)xaxis6 - 65;
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


	//Test 7: All full
	struct Truck Truck7[NUMTRUCKS] = {
	{0, 0.5, 'B'}, // Truck 0
	{0, 0.5, 'G'},  // Truck 1
	{0, 0.5, 'Y'}, // Truck 2
	};
	struct Shipment shipment7;
	double weight7 = 500, size7 = 1;
	int yaxis7 = 14;  char xaxis7 = 'U';
	if (validateWeight(weight7) == 1 && validateSize(size7) == 1 && validateAddress(yaxis7, xaxis7) == 1)
	{
		shipment7.weight = weight7;
		shipment7.size = size7;
		shipment7.dest.row = yaxis7 - 1;
		shipment7.dest.col = (int)xaxis7 - 65;
	}
	printf("Test 7: Should return -1\n");
	int result7 = findTruckForShipment(&deliveryMap, Truck7, shipment7);
	printf("Result: %d\n", result7);

	if (result7 == -1)
	{
		printf("Test 7 passed!\n\n");
	}
	else
	{
		printf("Test 7 failed!\n\n");
		pass = 0;
	}

	// Test 8: Enough size/not enough weight
	struct Truck Truck8[NUMTRUCKS] = {
	   {500, 3, 'B'}, // Truck 0
	   {100, 4, 'G'},  // Truck 1
	   {0, 3, 'Y'}, // Truck 2
	};
	struct Shipment shipment8;
	double weight8 = 500, size8 = 1;
	int yaxis8 = 13;   char xaxis8 = 'U';
	if (validateWeight(weight8) == 1 && validateSize(size8) == 1 && validateAddress(yaxis8, xaxis8) == 1)
	{
		shipment8.weight = weight8;
		shipment8.size = size8;
		shipment8.dest.row = yaxis8 - 1;
		shipment8.dest.col = (int)xaxis8 - 65;
	}
	printf("Test 8: Should return 0\n");
	int result8 = findTruckForShipment(&deliveryMap, Truck8, shipment8);
	printf("Result: %d\n", result8);

	if (result8 == 0)
	{
		printf("Test 8 passed!\n\n");
	}
	else
	{
		printf("Test 8 failed!\n\n");
		pass = 0;
	}



	// Test 9: Enough weight/not enough size
	struct Truck Truck9[NUMTRUCKS] = {
	   {500, 0.25, 'B'}, // Truck 0
	   {500, 0.25, 'G'},  // Truck 1
	   {500, 0.25, 'Y'}, // Truck 2
	};
	struct Shipment shipment9;
	double weight9 = 500, size9 = 1;
	int yaxis9 = 13;  char xaxis9 = 'U';
	if (validateWeight(weight9) == 1 && validateSize(size9) == 1 && validateAddress(yaxis9, xaxis9) == 1)
	{
		shipment9.weight = weight9;
		shipment9.size = size9;
		shipment9.dest.row = yaxis9 - 1;
		shipment9.dest.col = (int)xaxis9 - 65;
	}
	printf("Test 9: Should return -1\n");
	int result9 = findTruckForShipment(&deliveryMap, Truck9, shipment9);
	printf("Result: %d\n", result9);

	if (result9 == -1)
	{
		printf("Test 9 passed!\n\n");
	}
	else
	{
		printf("Test 9 failed!\n\n");
		pass = 0;
	}

	// Test 10: Enough weight/not enough size
	struct Truck Truck10[NUMTRUCKS] = {
	   {700, 1, 'B'}, // Truck 0
	   {700, 0.5, 'G'},  // Truck 1
	   {0, 3, 'Y'}, // Truck 2
	};
	struct Shipment shipment10;
	double weight10 = 500, size10 = 1;
	int yaxis10 = 13;  char xaxis10 = 'U';
	if (validateWeight(weight10) == 1 && validateSize(size10) == 1 && validateAddress(yaxis10, xaxis10) == 1)
	{
		shipment10.weight = weight10;
		shipment10.size = size10;
		shipment10.dest.row = yaxis10 - 1;
		shipment10.dest.col = (int)xaxis10 - 65;
	}
	printf("Test 10: Should return 0\n");
	int result10 = findTruckForShipment(&deliveryMap, Truck10, shipment10);
	printf("Result: %d\n", result10);

	if (result10 == 0)
	{
		printf("Test 10 passed!\n\n");
	}
	else
	{
		printf("Test 10 failed!\n\n");
		pass = 0;
	}


	// Test 11: Enough weight/not enough size
	struct Truck Truck11[NUMTRUCKS] = {
	   {100, 1, 'B'}, // Truck 0
	   {100, 1, 'G'},  // Truck 1
	   {100, 1, 'Y'}, // Truck 2
	};
	struct Shipment shipment11;
	double weight11 = 500, size11 = 1;
	int yaxis11 = 13;  char xaxis11 = 'U';
	if (validateWeight(weight11) == 1 && validateSize(size11) == 1 && validateAddress(yaxis11, xaxis11) == 1)
	{
		shipment11.weight = weight11;
		shipment11.size = size11;
		shipment11.dest.row = yaxis11 - 1;
		shipment11.dest.col = (int)xaxis11 - 65;
	}
	printf("Test 11: Should return -1\n");
	int result11 = findTruckForShipment(&deliveryMap, Truck11, shipment11);
	printf("Result: %d\n", result11);

	if (result11 == -1)
	{
		printf("Test 11 passed!\n\n");
	}
	else
	{
		printf("Test 11 failed!\n\n");
		pass = 0;
	}


	if (pass)
	{
		printf("Integration tests passed.\n\n");

	}
	else
	{
		printf("Integration tests failed.\n\n");
	}

};

int main() {
	runIntegrationTests();
	
	return 0;
}
