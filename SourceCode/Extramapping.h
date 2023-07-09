#pragma once

#define MAX_WEIGHT 1000
#define MAX_SIZE 36

#include "mapping.h"

struct Truck 
{
	int availWeight;
	int availSize;
};

struct Shipment {
	int weight;
	int size;
	struct Point dest;
};


