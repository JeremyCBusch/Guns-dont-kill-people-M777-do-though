#pragma once

class Velocity
{
public:
   Velocity(double dx = 0.0, double dy = 0.0);
   double operator / (double rhs) const;
   double operator * (const Velocity& rhs) const;
   void set(double dx = 0.0, double dy = 0.0);
#ifndef DEBUG
private:
#endif
   double getTotalVelocity() const;

   double dx;
   double dy;
};

