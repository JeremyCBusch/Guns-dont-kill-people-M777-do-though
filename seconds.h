#pragma once

#include "acceleration.h"
#include "velocity.h"

class Seconds
{
public:
	Velocity operator * (Acceleration acc);
//private:
	double seconds;
};

