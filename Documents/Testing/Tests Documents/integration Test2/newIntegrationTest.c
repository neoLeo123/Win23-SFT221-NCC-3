#include <stdio.h>
#include "mapping.h" 
#include "diy.h"

void runIntegrationTests() {

	int pass = 1;

	double weight, size;
	int num = 0;
	char letter = ' ';
	int valid, exit;


	struct Shipment shipment = { 0,0,{0,0} };
	struct Truck truck[NUMTRUCKS] = { {1000, 36, 'B'}, {1000, 36, 'G'}, {1000, 36, 'Y'} };

	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);

	printMap(&routeMap, 1, 1);


	// Test 1: Invalid destination 20 0.5 28x
	
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}
	
	// Test 2: Invalid size 20 2 12L
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}

	// Test 3: Invalid weight 1005 0.5 12L
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}

	// Test 4: Blue line no diversion 20 0.5 12L
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}

	// Test 5: Green line diversion 200 1.0 8Y
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}


	// Test 6: Green line diversion 500 1.0 8Y
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}

	// Test 7: Blue line diversion 500 1.0 8Y
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}


	// Test 8: Exit 0 0 x
	valid = getInput(&weight, &size, &letter, &num, &exit);
	if (!exit && valid)
	{
		getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
	}

	

};

int main() {
	

	runIntegrationTests();

	return 0;
}