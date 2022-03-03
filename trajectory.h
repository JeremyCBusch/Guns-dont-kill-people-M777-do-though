#pragma once
#define DEBUG

#include "position.h"
#include "velocity.h"
#include "acceleration.h"

enum Status {
	DEFAULT
};

class Trajectory
{
public:
	Trajectory();
	Trajectory(double angle, Velocity velocity, Acceleration acceleration, Position position);
	Position getPosition();
	void incrementTime(double seconds);
	void addAcceleration(Acceleration acceleration);
#ifndef DEBUG
private:
#endif
	Velocity velocity;
	Acceleration acceleration;
	Position position;
	double angle;
	Status status;
	Position pastPositions[];
};

