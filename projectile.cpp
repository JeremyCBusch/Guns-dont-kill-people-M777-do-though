#include "projectile.h"

Projectile::Projectile(Position pos, double angle) : temp(pos.getMetersX(), pos.getMetersY(), angle, 827)
{
   for (int i = 0; i < 20; i++)
   {
      positions[i].setPixelsX(pos.getPixelsX() + (double)i * 2.0);
      positions[i].setPixelsY(pos.getPixelsY());
   }
}

void Projectile::update()
{
   if (positions.size() == 0)
      return;
   Position prev = positions[0];
   std::pair<double, double> next = temp.update();
   positions[0].setMetersX(next.first);
   positions[0].setMetersY(next.second);

   for (int i = 1; i < TAIL_SIZE; i++)
   {
      auto curr = positions[i];
      positions[i].setMetersX(prev.getMetersX());
      positions[i].setMetersY(prev.getMetersY());
      prev = curr;
   }
}

void Projectile::draw(ogstream& gout)
{
	for (int i = 0; i < TAIL_SIZE; i++)
	{
		gout.drawProjectile(positions[i], 0.5 * (double)i);
	}
}

const Position& Projectile::getPosition()
{
   return positions[0];
}
