#include "simulator.h"

Simulator::Simulator(Position ptUpperRight, float FPS): environment(userInput, ptUpperRight, FPS),
	userInput(new UserInput()), gout(Position(10.0, ptUpperRight.getPixelsY() - 20.0)) {}

Simulator::~Simulator()
{
	delete userInput;
}

void Simulator::update()
{
	environment.update();
}

void Simulator::draw()
{
	environment.draw(gout);
}
