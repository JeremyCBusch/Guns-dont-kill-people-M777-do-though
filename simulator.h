#pragma once

#include "userInput.h"
#include "environment.h"


class Simulator
{
public:
	Simulator(Position ptUpperRight, float FPS);
	~Simulator();
	void update();
	void draw();


private:
	Environment environment;
	UserInput* userInput;
	ogstream gout;
};

