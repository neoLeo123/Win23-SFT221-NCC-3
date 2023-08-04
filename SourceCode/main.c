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

		if (weight == 0 && size == 0 && strcmp(str, "x") == 0)
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

			printf("%lf %lf %d %d\n", weight, size, num, letter);

			

			//printf("%lf %lf %c %c", weight, size, row, letter - 65);

			shipment.weight = weight;
			shipment.size = size;
			shipment.dest.row = num - 1;
			shipment.dest.col = letter - 65;
			printf("%lf %lf %d %d\n", shipment.weight, shipment.size, shipment.dest.row, shipment.dest.col);
			printf("%d\n", findTruckForShipment(&routeMap, truck, shipment));

		}


		



	} while (flag == 0);
	




	


	return 0;
}
