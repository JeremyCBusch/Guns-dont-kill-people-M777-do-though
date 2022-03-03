#pragma once
class Acceleration
{
public:
	Acceleration() : ddx(0.0), ddy(0.0) {}
	Acceleration(double totalAcceleration);
	Acceleration(double xAcceleration, double yAcceleration);
//private:
	double ddx;
	double ddy;
};

