#pragma once

#include "velocity.h"

class GroundSpy
{
public:
	static size_t numUpdateCalls;
	static size_t numResetCalls;
	static size_t numDrawCalls;
	void reset()
	{
		numResetCalls++;
	}
	void update()
	{
		numUpdateCalls++;
	}
	void draw()
	{
		numDrawCalls++;
	}
	static void resetStatistics()
	{
		numUpdateCalls = 0;
		numResetCalls = 0;
		numDrawCalls = 0;
	}
};

class HowitzerSpy
{
public:
	static size_t numUpdateCalls;
	static size_t numResetCalls;
	static size_t numDrawCalls;
	void reset()
	{
		numResetCalls++;
	}
	void update()
	{
		numUpdateCalls++;
	}
	void draw()
	{
		numDrawCalls++;
	}
	static void resetStatistics()
	{
		numUpdateCalls = 0;
		numResetCalls = 0;
		numDrawCalls = 0;
	}
};

class ProjectileSpy
{
public:
	Velocity vel;
	double altitude;
	static size_t numUpdateCalls;
	static size_t numResetCalls;
	static size_t numDrawCalls;
	static size_t getVelocityCalls;
	void reset()
	{
		numResetCalls++;
	}
	void update()
	{
		numUpdateCalls++;
	}
	void draw()
	{
		numDrawCalls++;
	}
	const Velocity& getVelocity()
	{
		getVelocityCalls++;
		return vel;
	}
	static void resetStatistics()
	{
		numUpdateCalls = 0;
		numResetCalls = 0;
		numDrawCalls = 0;
		getVelocityCalls = 0;
	}

};