#pragma once

#include "userInput.h"
#include "trajectory.h"
#include "uiDraw.h"
#include "projectile.h"
#include <list>

const double PI = 3.141592653589793;

class Howitzer
{
public:
   Howitzer();
   Howitzer(UserInput* input, std::list<Projectile>* firedProjs, const Position& pos = Position(0.0, 0.0)) :
      input(input), pos(pos), barrelAngle(PI), firedProjs(firedProjs) {}
   void set(UserInput* input, const Position& pos = Position(0.0, 0.0));
   void update();
   void draw(ogstream & gout, double time);
   void reset();
   void fire();
   Position& getPosition();
   // TODO: maybe return less
   Position getTarget();


#ifndef DEBUG
private:
#endif
   void rotateLeft(double angle);
   void rotateRight(double angle);
   Position getTipOfBarrelPos();

   double BASE_HEIGHT = 10.0;

   UserInput* input;
   std::list<Projectile>* firedProjs;
   Position pos;
   double barrelAngle;
   double barrelLength;
   bool fired = false;
   // TODO: if feeling adventurous, figure out how to get angle and
   //  length of barrel based on pos and tipPos
};

