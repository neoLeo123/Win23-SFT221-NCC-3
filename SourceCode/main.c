#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "diy.h"

int main(void)
{
	double weight = 0.0, size = 0.0;
	int num;
	char letter;

	struct Shipment shipment;
	struct Truck truck[NUMTRUCKS] = { {1000, 36, 'G'}, {1000, 36, 'B'}, {1000, 36, 'Y'} };
	
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);

	printMap(&routeMap, 1, 1);

	int valid = 1;
	do {

		valid = 1;
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");

		scanf("%lf %lf %d%c", &weight, &size, &num, &letter);		
		if (!validateWeight(weight)) {
			printf("Invalid weight (must be 1-1000 Kg.)\n");
			valid = 0;
		}
		if (!validateSize(size) && valid) {
			printf("Invalid size\n");
			valid = 0;
		}
		if (!validateAddress(num, letter) && valid) {
			printf("Invalid destination\n");
			valid = 0;
		}
	} while (!valid);

	shipment.weight = weight;
	shipment.size = size;
	shipment.dest.row = num;
	shipment.dest.col = letter;

	printf("%d", findTruckForShipment(&routeMap, truck, shipment));

	return 0;
}