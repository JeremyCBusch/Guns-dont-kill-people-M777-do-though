#pragma once

#include "userInput.h"
#include "acceleration.h"
#include "projectile.h"
#include "howitzer.h"
#include "ground.h"
#include "force.h"


class Environment
{
public:
   Environment(UserInput* input, Position ptUpperRight, float FPS);
   void update();
   void draw(ogstream& gout);
   void reset();
#ifndef DEBUG
private:
#endif
   Force getAirResistance();
   double getLinearInterpolation(double v0, double c0, double v1, double c1, double v);
   double getSpeedOfSound(double altitude);
   Acceleration getGravitationalAcceleration(double altitude);
   double getAirDensity(double altitude);
   double getDragCoefficient(double mach);
   double getMach();

   // member variables
   Projectile proj;
   Howitzer howitzer;
   Ground ground;
   bool isProjFired;

};


