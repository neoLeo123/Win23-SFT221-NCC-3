#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mapping.h"
#include "diy.h"

int main(void)
{
	double weight, size;
	int num=0;
	char letter;
	char str[4];
	

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


	 int flag = 0, flag2=0;
	 do {
		
		 char temp[3] = {'\0'};
			 printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
			 scanf("%lf %lf %s", &weight, &size, str);

			 if (weight == 0 && size ==0 && strcmp(str, "x")==0)
			 {
				 flag = 1;
				 printf("%s\n", str);
			 }
			 else
			 {
				 if (isdigit(str[0]))
				 {
					 temp[0] = str[0];
				 }
				 if (isdigit(str[1]))
				 {
					 temp[1] = str[1];
				 }
				 num = atoi(temp);
				 printf("%d\n", num);
				 printf("%c", temp[2]);
				 strcpy(letter, temp[2]);
				 printf("%c", letter);
				 getchar();

				// scanf(" %c", &letter);
				 if (!validateWeight(weight) && flag == 0) {
					 printf("Invalid weight (must be 1-1000 Kg.)\n");

				 }
				 if (!validateSize(size) && flag == 0) {
					 printf("Invalid size\n");

				 }
				 if (!validateAddress(num, letter) && flag == 0) {
					 printf("Invalid destination\n");
				 }
			 }
			 

			 /*if (weight == 0 && size == 0 && num == 'x') {
				 flag = 1;
			 }
			 else {
				 getchar();

				 scanf(" %c", &letter);
				 if (!validateWeight(weight) && flag == 0) {
					 printf("Invalid weight (must be 1-1000 Kg.)\n");

				 }
				 if (!validateSize(size) && flag == 0) {
					 printf("Invalid size\n");

				 }
				 if (!validateAddress(num, letter) && flag == 0) {
					 printf("Invalid destination\n");

				 }
			 }*/
		 
		 

	 } while (flag == 0);
	/*do
	{*/
		
		/*do {

			valid = 1;
			printf("Enter shipment weight, box size and destination (0 0 x to stop): ");

			scanf("%lf %lf %c %c", &weight, &size, &num, &letter);

			if (weight != 0 || size != 0 || letter != 'x')
			{
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
			}
			
		} while (!valid);
	} while (weight!= 0 || size != 0 || num != 'x');*/

	
	

	shipment.weight = weight;
	shipment.size = size;
	shipment.dest.row = num - 1;
	//shipment.dest.col = (int)(letter) - 65;
	//printf("%d %d", shipment.dest.row, shipment.dest.col);

	//printf("%d", findTruckForShipment(&routeMap, truck, shipment));

	return 0;
}
