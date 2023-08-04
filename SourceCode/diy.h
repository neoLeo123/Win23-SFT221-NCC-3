#pragma once

#define MAX_WEIGHT 1000
#define MAX_SIZE 36

#include "mapping.h"

struct Truck
{
	double availWeight;
	double availSize;
	char route;
};

struct Shipment {
	double weight;
	double size;
	struct Point dest;
};


