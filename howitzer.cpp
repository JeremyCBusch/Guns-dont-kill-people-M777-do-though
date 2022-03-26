#include "howitzer.h"

Howitzer::Howitzer() : input(nullptr), pos(), barrelAngle(3.14) {}

void Howitzer::set(UserInput* input, const Position& pos)
{
   this->input = input;
   this->pos = pos;
   this->barrelAngle = 3.14;
}


void Howitzer::update()
{
   const double FAST = 0.1;
   const double SLOW = 0.003;

   if (input->isLeft())
      rotateLeft(FAST);

   if (input->isRight())
      rotateRight(FAST);

   // move by a little
   if (input->isUp())
      barrelAngle >= PI ? rotateLeft(0.003) : rotateRight(0.003); // TODO: they both always go toward the center
   if (input->isDown())
      barrelAngle < PI ? rotateLeft(0.003) : rotateRight(0.003);

   if (input->isSpacePressed())
      fire();
}

void Howitzer::draw(ogstream& gout, double time)
{
   gout.drawHowitzer(pos, barrelAngle - PI, time);
}

void Howitzer::reset()
{
   barrelAngle = PI;
}

void Howitzer::rotateLeft(double angle)
{
   std::cout << "Left" << std::endl;
   barrelAngle -= angle;

   if (barrelAngle > 3.0 * PI / 2.0)
      barrelAngle = 3.0 * PI / 2.0;
   if (barrelAngle < PI / 2.0)
      barrelAngle = PI / 2.0;
}

void Howitzer::rotateRight(double angle)
{
   std::cout << "Right" << std::endl;
   barrelAngle += angle;

   if (barrelAngle < PI / 2)
      barrelAngle = PI / 2;
   if (barrelAngle > 3.0 * PI / 2)
      barrelAngle = 3.0 * PI / 2;
}

// Return the position of the barrel's tip, you'll probs have to do
// some fancy math
Position Howitzer::getTipOfBarrelPos()
{

   double yPosRelativeToM777 = sin(barrelAngle) * barrelLength;
   double xPosRelativeToM777 = cos(barrelAngle) * barrelLength;
   double tipXPos;
   if (barrelAngle > PI / 2.0)
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

void Howitzer::fire()
{
   firedProjs->push_back(Projectile(pos, barrelAngle - PI));
}

Position& Howitzer::getPosition()
{
   return pos;
}
