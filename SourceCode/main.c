#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mapping.h"
#include "diy.h"

int main(void)
{
	double weight, size;
	int num = 0;
	char letter = ' ';
	//char str[4];
	//char row, col;
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


	//int exit = 0, valid = 1;
	//do {
	//	valid = 1;
	//	char temp[3];
	//	printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
	//	scanf("%lf %lf %s", &weight, &size, str);

	//	if (weight == 0.0 && size == 0.0 && strcmp(str, "x") == 0)
	//	{
	//		exit = 1;

	//	}
	//	else
	//	{
	//		int i = 0;
	//		while (str[i] != '\0' && isdigit(str[i]))
	//		{
	//			temp[i] = str[i];
	//			i++;
	//		}
	//		temp[i] = '\0';
	//		letter = str[i];
	//		num = atoi(temp);

	//		if (!validateWeight(weight) && exit == 0) {
	//			printf("Invalid weight (must be 1-1000 Kg.)\n");
	//			valid = 0;
	//		}
	//		if (!validateSize(size) && exit == 0) {
	//			printf("Invalid size\n");
	//			valid = 0;
	//		}
	//		if (!validateAddress(num, letter) && exit == 0) {
	//			printf("Invalid destination\n");
	//			valid = 0;
	//		}

	//		if (valid)
	//		{
	//			shipment.weight = weight;
	//			shipment.size = size;
	//			shipment.dest.row = num - 1;
	//			shipment.dest.col = letter - 65;
	//			//printf("%lf %lf %d %d\n", shipment.weight, shipment.size, shipment.dest.row, shipment.dest.col);
	//			//printf("%d\n", findTruckForShipment(&routeMap, truck, shipment));

	//			int truckIdx = findTruckForShipment(&routeMap, truck, shipment);
	//			truck[truckIdx].availWeight -= shipment.weight;
	//			truck[truckIdx].availSize -= shipment.size;
	//			//printf("%lf %lf %c\n", truck[truckIdx].availWeight, truck[truckIdx].availSize, truck[truckIdx].route);




	//			//printf("%d\n", truckIdx);
	//			//printf("%lf %lf %c\n", truck[truckIdx].availWeight, truck[truckIdx].availSize, truck[truckIdx].route);
	//			struct Route route = getRouteFromTruck(truck[truckIdx]);


	//			int shortestIdx = -1;
	//			int shortest = 100;
	//			struct Route shortestRoute = { {0, 0}, 0, 0 };
	//			//int pathLength;
	//			//printf("%d\n", route.numPoints);

	//			/*for (int i = 0; i < route.numPoints; i++)
	//			{
	//				printf("%d: %d\n", i, shortestPath(&routeMap, route.points[i], shipment.dest).numPoints);

	//			}*/

	//			for (int i = 0; i < route.numPoints; i++) {
	//				//int pathLength = shortestPath(&routeMap, route.points[i], shipment.dest).numPoints;
	//				if (shortestPath(&routeMap, route.points[i], shipment.dest).numPoints < shortest) {
	//					shortestRoute = shortestPath(&routeMap, route.points[i], shipment.dest);
	//					shortest = shortestPath(&routeMap, route.points[i], shipment.dest).numPoints;
	//					shortestIdx = i;
	//				}
	//			}

	//			switch (truckIdx) {
	//			case 0:
	//				printf("Ship on BLUE LINE, ");
	//				break;
	//			case 1:
	//				printf("Ship on GREEN LINE, ");
	//				break;
	//			case 2:
	//				printf("Ship on YELLOW LINE, ");
	//				break;
	//			}
	//			if (shortest) {
	//				printf("divert: ");
	//				printf("%d%c, ", route.points[shortestIdx].row + 1, (char)(route.points[shortestIdx].col + 65));
	//				for (int i = 0; i < shortest; i++) {
	//					printf("%d%c, ", shortestRoute.points[i].row + 1, (char)(shortestRoute.points[i].col + 65));
	//				}
	//				printf("%d%c", shipment.dest.row + 1, (char)(shipment.dest.col + 65));
	//				printf("\n");
	//			}
	//			else {
	//				printf("no diversion\n");
	//			}


	//		}


	//	}

	//} while (exit == 0);

	do
	{
		valid = getInput(&weight, &size, &letter, &num, &exit);
		if (!exit && valid)
		{
			getShortestRoute(&routeMap, truck, shipment, weight, size, letter, num);
		}
	} while (exit == 0);






	return 0;
}
