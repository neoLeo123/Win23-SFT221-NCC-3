#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "math.h"
#include "diy.h"
//struct Truck Trucks[NUMTRUCKS];
//struct Shipment shipment;
struct Map populateMap() {
	struct Map result = {
		//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
		//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
		{
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
		{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
		{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
		},
		MAP_ROWS, MAP_COLS
	};
	return result;
}

int getNumRows(const struct Map* map) {
	return map->numRows;
}

int getNumCols(const struct Map* map) {
	return map->numCols;
}

void printMap(const struct Map* map, const int base1, const int alphaCols) {
	//              01234567890123456
	//              1248F
	char sym[] = { " XB?G?.?Y?-?*?+?P" };
	int r, c, rowMax;

	rowMax = map->numRows + base1;

	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++) {
		if (alphaCols) printf("%c", 'A' + c);
		else printf("%d", c % 10);
	}
	printf("\n");
	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++) {
		printf("-");
	}
	printf("\n");

	for (r = base1; r < rowMax; r++) {
		printf("%3d|", r);
		for (c = 0; c < map->numCols; c++) {
			printf("%c", sym[map->squares[r - base1][c]]);
		}
		printf("\n");
	}
}

struct Route getBlueRoute() {
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
			{5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10},
			{11, 10},
			{12, 10},
			{13, 10},
			{14, 10},
			{15, 10},
			{16, 10},
			{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, BLUE
	};
	return result;
}

struct Route getGreenRoute() {
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
			{3, 11},
			{2, 11},
			{1, 11},
			{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
			{1, 19},
			{2, 19},
			{3, 19},
			{4, 19},
			{5, 19},
			{6, 19},
			{7, 19},
			{8, 19},
			{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}
		},
			42, GREEN
	};
	return result;
}

struct Route getYellowRoute() {
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
	};
	return result;
}

struct Map addRoute(const struct Map* map, const struct Route* route) {
	int r, c;
	struct Map result = { {0}, 0 };

	for (r = 0; r < map->numRows; r++) {
		for (c = 0; c < map->numCols; c++) {
			result.squares[r][c] = map->squares[r][c];
		}
	}
	result.numRows = map->numRows;
	result.numCols = map->numCols;

	for (r = 0; r < route->numPoints; r++) {
		result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
	}

	return result;
}

void addPtToRoute(struct Route* route, struct Point pt) {
	route->points[route->numPoints++] = pt;
}

void addPointToRoute(struct Route* route, const int row, const int col) {
	struct Point pt = { row, col };
	addPtToRoute(route, pt);
}

void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis) {
	struct Point pt = { row, col };
	if (notThis.row != row || notThis.col != col) addPtToRoute(route, pt);
}

double distance(const struct Point* p1, const struct Point* p2) {
	int deltaRow = p2->row - p1->row;
	int deltaCol = p2->col - p1->col;

	return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest) {
	struct Route result = { {0,0}, 0, DIVERSION };
	struct Point last = { -1, -1 };
	struct Point current = start;
	struct Route possible = { {0,0},0,0 };
	int close = 0;

	while (!eqPt(current, dest) && close >= 0) {
		possible = getPossibleMoves(map, current, last);
		close = getClosestPoint(&possible, dest);
		if (close >= 0) {
			last = current;
			current = possible.points[close];
			addPtToRoute(&result, current);
		}
	}

	return result;
}

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath) {
	struct Route result = { {0,0}, 0, DIVERSION };

	if (p1.row > 0) {
		if (map->squares[p1.row - 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath);	// square above
		if (p1.col > 0 && map->squares[p1.row - 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col - 1, backpath);	// top left
		if (p1.col < (map->numCols - 1) && map->squares[p1.row - 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath);	// top right
	}
	if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath);	// left
	if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath);	// right
	if (p1.row < (map->numRows - 1)) {
		if (map->squares[p1.row + 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath);	// square below
		if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath);	// bot left
		if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col + 1, backpath);	// top right
	}

	return result;
}

int getClosestPoint(const struct Route* route, const struct Point pt) {
	int i, closestIdx = -1;
	double closestDist = 999999.9, dist;

	for (i = 0; i < route->numPoints; i++) {
		dist = distance(&pt, &route->points[i]);
		if (dist < closestDist) {
			closestDist = dist;
			closestIdx = i;
		}
	}
	return closestIdx;
}

int eqPt(const struct Point p1, const struct Point p2) {
	return p1.row == p2.row && p1.col == p2.col;
}

//====================================================
int validateWeight(double weight) {
	if (weight >= 1 && weight <= 1000) {
		return 1;
	}
	else {
		return 0;
	}
}

int validateSize(double size) {
	if (size == 0.25 || size == 0.5 || size == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int validateAddress(char y, char x) {
	if (y >= 0 && y <= MAP_ROWS && x >= 0 && x <= MAP_COLS) {
		return 1;
	}
	else {
		return 0;
	}
}

int findTruckForShipment(struct Map* deliveryMap, struct Truck Trucks[], struct Shipment shipment) {
	// Filter out trucks that cannot hold the shipment
	int validTrucks[NUMTRUCKS];
	int validTruckCount = 0;
	for (int i = 0; i < NUMTRUCKS; i++) {
		if (shipment.size <= Trucks[i].availSize && shipment.weight <= Trucks[i].availWeight) {
			validTrucks[i] = 1;
			validTruckCount++;
		}
	}

	// If no truck can hold the shipment, return -1
	if (validTruckCount == 0) {
		return -1;
	}

	struct Point destination = shipment.dest;

	// Find the closest point on each truck's route to the destination
	int closestPoints[NUMTRUCKS];
	for (int i = 0; i < NUMTRUCKS; i++) {
		if (validTrucks[i] == 1) {
			struct Route route = getRouteFromTruck(Trucks[i]);
			closestPoints[i] = getClosestPoint(&route, destination);
		}
	}

	// Find the shortest distance among the valid trucks' routes
	double shortestDistance = -1;
	for (int i = 0; i < NUMTRUCKS; i++) {
		if (closestPoints[i] >= 0) {
			struct Route route = getRouteFromTruck(Trucks[i]);
			double distance1 = distance(&route.points[closestPoints[i]], &destination);
			if (shortestDistance == -1 || distance1 < shortestDistance) {
				shortestDistance = distance1;
			}
		}
	}

	// Filter the trucks that have the shortest distance
	int shortestDistanceTrucks[NUMTRUCKS];
	int shortestDistanceTruckCount = 0;
	for (int i = 0; i < NUMTRUCKS; i++) {
		if (validTrucks[i] == 1) {
			struct Route route = getRouteFromTruck(Trucks[i]);
			double distance1 = distance(&route.points[closestPoints[i]], &destination);
			if (distance1 == shortestDistance) {
				shortestDistanceTrucks[i] = validTrucks[i];
				shortestDistanceTruckCount++;
			}
		}
	}

	// If there is only one truck with the shortest path, return that truck
	if (shortestDistanceTruckCount == 1) {
		for (int i = 0; i < NUMTRUCKS; i++) {
			if (shortestDistanceTrucks[i] == validTrucks[i]) {
				return i;
			}
		}
	}

	double limitingFactors[NUMTRUCKS];
	double maxFactor = 0;
	int res = -1;
	if (shortestDistanceTruckCount > 1) {
		for (int i = 0; i < NUMTRUCKS; i++) {
			if (shortestDistanceTrucks[i] == validTrucks[i]) {
				double weightFactor = Trucks[i].availWeight * 1.0 / MAX_WEIGHT;
				double sizeFactor = Trucks[i].availSize * 1.0 / MAX_SIZE;
				limitingFactors[i] = weightFactor + sizeFactor;
			}
		}
		for (int i = 0; i < NUMTRUCKS; i++) {
			if (shortestDistanceTrucks[i] == validTrucks[i]) {
				if (limitingFactors[i] > maxFactor) {
					maxFactor = limitingFactors[i];
					res = i;
				}
			}
		}
	}
	return res;

	// Sort the trucks with equidistant paths based on available capacity remaining
	//for (int i = 0; i < shortestDistanceTruckCount - 1; i++) {
	//	for (int j = i + 1; j < shortestDistanceTruckCount; j++) {
	//		int capacity_i = (Trucks[shortestDistanceTrucks[i]].availWeight / 1000) < (Trucks[shortestDistanceTrucks[i]].availSize / 36) ? (Trucks[shortestDistanceTrucks[i]].availWeight / 1000) : (Trucks[shortestDistanceTrucks[i]].availSize / 36);
	//		int capacity_j = (Trucks[shortestDistanceTrucks[j]].availWeight / 1000) < (Trucks[shortestDistanceTrucks[j]].availSize / 36) ? (Trucks[shortestDistanceTrucks[j]].availWeight / 1000) : (Trucks[shortestDistanceTrucks[j]].availSize / 36);

	//		if (capacity_i > capacity_j) {
	//			// Swap the trucks in the shortestDistanceTrucks array to achieve sorting
	//			int temp = shortestDistanceTrucks[i];
	//			shortestDistanceTrucks[i] = shortestDistanceTrucks[j];
	//			shortestDistanceTrucks[j] = temp;
	//		}
	//	}
	//}

	// Return the index of the best truck for the shipment
	//return shortestDistanceTrucks[0];
}

struct Route getRouteFromTruck(struct Truck truck) {
	struct Route returnRoute = { 0 };
	switch (truck.route) {
	case 'Y': returnRoute = getYellowRoute();
		break;
	case 'G': returnRoute = getGreenRoute();
		break;
	case 'B': returnRoute = getBlueRoute();
		break;
	}
	return returnRoute;
}