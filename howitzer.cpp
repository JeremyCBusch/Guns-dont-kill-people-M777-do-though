#include "howitzer.h"

Howitzer::Howitzer(UserInput* input, const Position& pos) : input(input), pos(pos)
{

}

void Howitzer::update()
{
   if (input->isLeft())
      rotateLeft(0.01);

   if (input->isRight())
      rotateRight(0.01);

   if (input->isSpacePressed())
      fire();
}

void Howitzer::draw()
{

}

void Howitzer::reset() // TODO: find out if we need to pass in a position
{
   barrelAngle = 3.14;
}

void Howitzer::rotateLeft(double angle)
{
   barrelAngle -= angle;

   if (barrelAngle > 3 * 3.14 / 2)
      barrelAngle = 3 * 3.14 / 2;
}

void Howitzer::rotateRight(double angle)
{
   barrelAngle += angle;

   if (barrelAngle < 3.14 / 2)
      barrelAngle = 3.14 / 2;
}

// Return the position of the barrel's tip, you'll probs have to do
// some fancy math
Position Howitzer::getTipOfBarrelPos()
{

   double yPosRelativeToM777 = sin(barrelAngle) * barrelLength;
   double xPosRelativeToM777 = cos(barrelAngle) * barrelLength;
   double tipXPos;
   if (barrelAngle > 3.14 / 2.0)
   {
      tipXPos = pos.getMetersX() - xPosRelativeToM777;
      //note the xPos is the M777 position
   }
   else
   {
      tipXPos = pos.getMetersX() + xPosRelativeToM777;
      //note the yPos is the M777 position
   }

   double tipYPos = yPosRelativeToM777 + BASE_HEIGHT;
   return { tipXPos, tipYPos };
}

Trajectory Howitzer::fire()
{

   return { getTipOfBarrelPos(), barrelAngle };
}