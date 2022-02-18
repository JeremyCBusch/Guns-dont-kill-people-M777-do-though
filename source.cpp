#include <iostream>
#include <cassert>
#include <cmath>
#include <map>
const double weight = 46.7;
const double area = .018842;

#define DEBUG

/*
 * Things we will need
 *    acceleration class
 *       - velocity
 *       - time
 *    velocity class
 *       - ddx
 *       - ddy
 *    atmosphere class
 *       - 
 *    projectile class
 *       - altitude
 *       - position
 *       - velocity
 *       - direction
 *       update time()
 *    cannon class
 *       shoot()
 *       aim()
 *    gravity class
 *       update elevation()
 *    speed of sound
 *       update elevation()
 *    drag class
 *       update elevation()
 *    air density
 *       update elevation()
 *       
 */



double getLinearInterpolation()
{
   //double interpolation = 0;

   //return interpolation;
   return 0.0;
}

double getSpeedOfSound(double altitude)
{
   std::map<double, double> soundSpeedTable({
      { 0,     340 },
      { 1000,  336 },
      { 2000,	332 },
      { 3000,	328 },
      { 4000,	324 },
      { 5000,	320 },
      { 6000,	316 },
      { 7000,	312 },
      { 8000,	308 },
      { 9000,	303 },
      { 10000,	299 },
      { 15000,	295 },
      { 20000,	295 },
      { 25000,	295 },
      { 30000,	305 },
      { 40000,	324 }
   });
   //// need to make a map that holds altittude and speed of sound
   //double speed = 0;

   //return speed;
   return 0.0;
}

double getGravitationalForce(double altitude)
{
   std::map<double, double> gravityForceTable({
      { 0,	   9.807 },
      { 1000,  9.804 },
      { 2000,  9.801 },
      { 3000,  9.797 },
      { 4000,  9.794 },
      { 5000,  9.791 },
      { 6000,  9.788 },
      { 7000,  9.785 },
      { 8000,  9.782 },
      { 9000,  9.779 },
      { 10000, 9.776 },
      { 15000, 9.761 },
      { 20000, 9.745 },
      { 25000, 9.730 }
   });
   return 0.0;
}

double getAirDensity(double altitude)
{
   std::map<double, double> airDensityTable({
      {     0,	1.2250000 },
      {  1000,	1.1120000 },
      {  2000,	1.0070000 },
      {  3000,	0.9093000 },
      {  4000,	0.8194000 },
      {  5000,	0.7364000 },
      {  6000,	0.6601000 },
      {  7000,	0.5900000 },
      {  8000,	0.5258000 },
      {  9000,	0.4671000 },
      { 10000,	0.4135000 },
      { 15000,	0.1948000 },
      { 20000,	0.0889100 },
      { 25000,	0.0400800 },
      { 30000,	0.0184100 },
      { 40000,	0.0039960 },
      { 50000,	0.0010270 },
      { 60000,	0.0003097 },
      { 70000,	0.0000828 },
      { 80000,	0.0000185 }
   });
   return 0.0;
}

double getDragCoefficient(double machAndCheese)
{
   std::map<double, double> machTable({
      { 0.300 , 0.1629 },
      { 0.500 , 0.1659 },
      { 0.700 , 0.2031 },
      { 0.890 , 0.2597 },
      { 0.920 , 0.3010 },
      { 0.960 , 0.3287 },
      { 0.980 , 0.4002 },
      { 1.000 , 0.4258 },
      { 1.020 , 0.4335 },
      { 1.060 , 0.4483 },
      { 1.240 , 0.4064 },
      { 1.530 , 0.3663 },
      { 1.990 , 0.2897 },
      { 2.870 , 0.2297 },
      { 2.890 , 0.2306 },
      { 5.000 , 0.2656 }
   });
   return 0.0;
}

double getTheMachAndCheese(double currentSpeed, double altitude) // minus the cheese
{
   return currentSpeed / getSpeedOfSound(altitude);
}

double getTheForceOfAirResistance(double altitude, double velocity, double area)
{
   return 0.5 * getDragCoefficient(getTheMachAndCheese(velocity, altitude)) * getAirDensity(altitude) * (velocity * velocity) * area;
}


double computeAcceleration(double force, double weight, double altitude, double velocity, double area, double gravity = 0.0)
{
   //assert(force > 0.0);
   //assert(weight > 0.0);
   double acceleration = force / weight;


   assert(gravity <= 0.0);
   return gravity + acceleration - (getTheForceOfAirResistance(altitude, velocity, area) / weight);
}



double getXVelocity(double angle, double velocity)
{
   double xVelocity = 0;
   // assuming the angle is in radians
   xVelocity = sin(angle) * velocity;
   return xVelocity;
}

double getYVelocity(double angle, double velocity)
{
   double yVelocity = 0;
   // assuming the angle is in radians
   yVelocity = cos(angle) * velocity;
   return yVelocity;
}

double getXAcceleration(double hThrust, double weight, double angle, double altitude, double velocity, double area)
{
   //need to add drag to this
   double force = hThrust * sin(angle);
   return computeAcceleration(force, weight, altitude, velocity, area) * /* why? ----> */100; // if youre getting weird numbers this is probably why FYI
}

double getYAcceleration(double vThrust, double weight, double angle, double altitude, double velocity, double area)
{
   //need to add drag to this
   double force = vThrust * cos(angle);
   return computeAcceleration(force, weight, altitude, velocity, area, getGravitationalForce(altitude));

}

double getXDistanceTraveled(double xVelocity, double xAcceleration, double seconds)
{
   return -1 * (xVelocity * seconds + 0.5 * xAcceleration * (seconds * seconds));
}

double getYDistanceTraveled(double yVelocity, double yAcceleration, double seconds)
{
   return yVelocity * seconds + 0.5 * yAcceleration * (seconds * seconds);
}

double getTotalXDistanceTraveled(double angle, double velocity)
{
   double xpos = 0.0;
   double ypos = 0.0;
   
   do 
   {
      ypos += getYDistanceTraveled(getYVelocity(angle, velocity), getYAcceleration(0, weight, angle, ypos, velocity, area), .5);
      xpos += getXDistanceTraveled(getXVelocity(angle, velocity), getXAcceleration(0, weight, angle, xpos, velocity, area), .5);

   } while (ypos > 0.0);
   

   /*
    * loop
    *    increment time .5 sec
    *    check y pos
    *    if y pos <= 0
    *       break
    * do linear interpolation on y to find x
    * calculate seconds using linear interpolation too
    *    
    *    
    */
   //return (position.getY() + getXDistanceTraveled());
   return xpos;
}


 // dimadome 



double computeTotalVelocity(double vVelocity, double hVelocity)
{
   return sqrt(vVelocity * vVelocity + hVelocity * hVelocity);
}



double convertDegreesToRadians(double degrees)
{
   const double pi = 3.14159265358979323846;
   return (2 * pi * degrees) / 360;
}



#ifdef DEBUG
void test_getTotalDistanceTraveled()
{
   std::cout << "test_getTotalDistanceTraveled not yet implemented" << std::endl;
}

void test_getYDistanceTraveled()
{
   // getYDistanceTraveled(double yVelocity, double yAcceleration, double seconds);
   assert(getYDistanceTraveled(0.0, 0.0, 0.0) == 0.0);
}

void testAll()
{
   test_getTotalDistanceTraveled();
   test_getYDistanceTraveled();
}

#endif

int main()
{
#ifdef DEBUG
   testAll();
#else
   std::cout << "Hello Jeremy!" << std::endl;
   return 0;
#endif
   getTotalXDistanceTraveled(30, 827);
}