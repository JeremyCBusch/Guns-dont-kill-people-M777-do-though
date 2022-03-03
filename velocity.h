#pragma once
#include "position.h"
#include "acceleration.h"

class Velocity
{
public:
	Velocity() : dx(0.0), dy(0.0) {}
	Velocity(double totalVelocity);
	Velocity(double xVelocity, double yVelocity);
	void operator += (Acceleration acceleration);
	double operator * (Velocity rhs);
	Velocity operator + (Velocity rhs);
	Velocity operator * (double rhs);

//private:
	double computeTotalVelocity();
	double dx;
	double dy;
};

