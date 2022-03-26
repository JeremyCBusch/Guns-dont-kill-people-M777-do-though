#pragma once

#include <array>
#include "trajectory.h"
#include "position.h"
#include "uiDraw.h"
#include "tempMath.h"

const int TAIL_SIZE = 20;

class Projectile
{
public:
	Projectile(Position pos, double angle);
	void update();
	void draw(ogstream& gout);
	const Position& getPosition();
private:
	Trajectory trajectory;
	std::array<Position, TAIL_SIZE> positions;
	MEGATEMPDONOTUSELATER temp;
};

