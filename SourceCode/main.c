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
