#pragma once

#include "force.h"
#include "acceleration.h"

class Mass
{
public:
	Force operator * (Acceleration acc);
	//private:
	double kgs;
};

