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
	char str[4];
	char row, col;


	struct Shipment shipment;
	struct Truck truck[NUMTRUCKS] = { {1000, 36, 'B'}, {1000, 36, 'G'}, {1000, 36, 'Y'} };

	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);

	printMap(&routeMap, 1, 1);


	int flag = 0, flag2 = 0;
	do {

		char temp[3];
		printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
		scanf("%lf %lf %s", &weight, &size, str);

		if (weight == 0.0 && size == 0.0 && strcmp(str, "x") == 0)
		{
			flag = 1;
		
		}
		else
		{
			int i = 0;
			while (str[i] != '\0' && isdigit(str[i]))
			{
				temp[i] = str[i];
				i++;
			}
			temp[i] = '\0';
			letter = str[i];
			num = atoi(temp);

			if (!validateWeight(weight) && flag == 0) {
				printf("Invalid weight (must be 1-1000 Kg.)\n");

			}
			if (!validateSize(size) && flag == 0) {
				printf("Invalid size\n");

			}
			if (!validateAddress(num, letter) && flag == 0) {
				printf("Invalid destination\n");
			}
			
			shipment.weight = weight;
			shipment.size = size;
			shipment.dest.row = num - 1;
			shipment.dest.col = letter - 65;
			printf("%lf %lf %d %d\n", shipment.weight, shipment.size, shipment.dest.row, shipment.dest.col);
			printf("%d\n", findTruckForShipment(&routeMap, truck, shipment));

			int truckIdx = findTruckForShipment(&routeMap, truck, shipment);

			printf("%d\n", truckIdx);
			printf("%lf %lf %c\n", truck[truckIdx].availWeight, truck[truckIdx].availSize, truck[truckIdx].route);
			//struct Route route = getRouteFromTruck(truck[truckIdx]);
			

			int shortestIdx;
			int shortest = 100;
			struct Route shortestRoute;
			//int pathLength;
			printf("%d\n", greenRoute.numPoints);

			for (int i = 0; i < greenRoute.numPoints; i++)
			{
				printf("%d: %d\n", i, shortestPath(&routeMap, greenRoute.points[i], shipment.dest).numPoints);

			}

			for (int i = 0; i < greenRoute.numPoints; i++)
			{
				if (shortestPath(&routeMap, greenRoute.points[i], shipment.dest).numPoints < shortest)
				{
					shortestRoute = shortestPath(&routeMap, greenRoute.points[i], shipment.dest);
					shortest = shortestPath(&routeMap, greenRoute.points[i], shipment.dest).numPoints;
					shortestIdx = i;
					
				}
			}
			
			for (int i = 0; i < shortest; i++)
			{
				printf("%d %d\n", shortestRoute.points[i].row, shortestRoute.points[i].col);
			}
			//shortestPath(&routeMap, route.points[shortestIdx], shipment.dest);
			/*int ret=0;
			struct Route final;*/
			//if (findTruckForShipment(&routeMap, truck, shipment)==0)
			//{
			//	//ret = getClosestPoint(&blueRoute, shipment.dest);
			//	ret = shortestPath(&routeMap, )
			//}
			//else if (findTruckForShipment(&routeMap, truck, shipment) == 1)
			//{
			//	ret = getClosestPoint(&greenRoute, shipment.dest);
			//}
			//else if (findTruckForShipment(&routeMap, truck, shipment) == 2)
			//{
			//	ret = getClosestPoint(&yellowRoute, shipment.dest);
			//}
			/*printf("%d", ret);
			final = getPossibleMoves(&routeMap, point[ret].start, shipment.dest);*/
			/*while (final[i] != '\0')
			{

			}*/
			//getPossibleMoves(&routeMap, truck[ret].start, shipment.dest);
		}

	} while (flag == 0);
	




	


	return 0;
}
