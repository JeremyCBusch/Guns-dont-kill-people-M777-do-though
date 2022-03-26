#pragma once

#include <cmath>
#include <map>
#include <iostream>
#include <cassert>



class MEGATEMPDONOTUSELATER
{
public:
   MEGATEMPDONOTUSELATER(double x, double y, double angle, double velocity)
   {
      xpos = x;
      ypos = y;

      seconds = 0.0;

      radAngle = angle;

      yVelocity = getYVelocity(radAngle, velocity);
      xVelocity = getXVelocity(radAngle, velocity);
   }
   std::pair<double, double> update()
   {
      radAngle = atan(xVelocity / yVelocity);
      totalVelocity = computeTotalVelocity(yVelocity, xVelocity);
      xAcceleration = getXAcceleration(weight, radAngle, ypos, totalVelocity, area);
      yAcceleration = getYAcceleration(weight, radAngle, ypos, totalVelocity, area);

      ypos += getDistanceTraveled(yVelocity, yAcceleration, 0.5);
      xpos += getDistanceTraveled(xVelocity, xAcceleration, 0.5);

      yVelocity += 0.5 * yAcceleration;
      xVelocity += 0.5 * xAcceleration;
      seconds += 0.5;
      
      return {xpos, ypos};
   }
private:
   double xpos;
   double ypos;

   double seconds;

   double radAngle;
   double yVelocity;
   double xVelocity;

   double totalVelocity;
   double yAcceleration;
   double xAcceleration;

   const double weight = 46.7;
   const double area = 0.018842;

   double computeTotalVelocity(double vVelocity, double hVelocity)
   {
      double normalizer = (vVelocity >= 0.0 && hVelocity < 0.0) || (vVelocity < 0.0 && hVelocity >= 0.0) ? -1.0 : 1.0;
      return normalizer * sqrt(vVelocity * vVelocity + hVelocity * hVelocity);
   }


   /*
    * CONVERT DEGREES TO RADIANS
    *
    */
   double convertDegreesToRadians(double degrees)
   {
      const double pi = 3.14159265358979323846;
      return (2 * pi * degrees) / 360;
   }



   double getLinearInterpolation(double v1, double c1, double v0, double c0, double v)
   {
      if (v1 == v1)
         return c1;
      return c0 + ((v - v0) * (c1 - c0)) / (v1 - v0);
   }

   double getSpeedOfSound(double altitude)
   {
      std::map<double, double> soundSpeedTable({
         { 0.0,      340.0 },
         { 1000.0,   336.0 },
         { 2000.0,	332.0 },
         { 3000.0,	328.0 },
         { 4000.0,	324.0 },
         { 5000.0,	320.0 },
         { 6000.0,	316.0 },
         { 7000.0,	312.0 },
         { 8000.0,	308.0 },
         { 9000.0,	303.0 },
         { 10000.0,	299.0 },
         { 15000.0,	295.0 },
         { 20000.0,	295.0 },
         { 25000.0,	295.0 },
         { 30000.0,	305.0 },
         { 40000.0,	324.0 }
         });
      double keys[] = { 0,1000,2000,3000,4000,5000,6000,7000,
         8000,9000,10000,15000,20000,25000,30000,40000 };
      // need to make a map that holds altitude and speed of sound
      double prev = 0.0;
      for (double key : keys)
      {
         if (altitude <= key)
         {
            return getLinearInterpolation(
               key, soundSpeedTable.at(key), prev,
               soundSpeedTable.at(prev), altitude);
         }
         prev = key;
      }
      //assert(false); // our value is too big
      std::cout << "getSpeedOfSound: Altitude is a bit too high" << std::endl;


      return 324.0;
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
      double keys[] = { 0,1000,2000,3000,4000,5000,6000,
         7000,8000,9000,10000,15000,20000,25000 };
      double prev = 0;
      for (double key : keys)
      {
         if (altitude <= key)
         {
            return -1 * getLinearInterpolation(
               key, gravityForceTable.at(key), prev,
               gravityForceTable.at(prev), altitude);
         }
         prev = key;
      }
      //assert(false); // our value is too big
      std::cout << "getGravitationalForce: Altitude is a bit too high" << std::endl;




      return -1 * 9.73;
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
      double keys[] = { 0,1000,2000,3000,4000,5000,6000,
         7000,8000,9000,10000,15000,20000,25000,30000,
         40000,50000,60000,70000,80000 };

      double prev = 0;
      for (double key : keys)
      {
         if (altitude <= key)
         {
            return getLinearInterpolation(
               key, airDensityTable.at(key), prev,
               airDensityTable.at(prev), altitude);
         }
         prev = key;
      }
      //assert(false); // our value is too big
      std::cout << "getAirDensity: Altitude is a bit too high" << std::endl;

      return 0.0000185;
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

      double keys[] = { 0.300,0.500,0.700,0.890,0.920,
         0.960,0.980,1.000,1.020,1.060,1.240,1.530,
         1.990,2.870,2.890,5.000 };

      double prev = 0.300;
      for (double key : keys)
      {
         if (machAndCheese <= key)
         {
            return getLinearInterpolation(
               key, machTable.at(key), prev,
               machTable.at(prev), machAndCheese);
         }
         prev = key;
      }
      //assert(false); // our value is too big
      std::cout << "getDragCoefficient: Mach is a bit too high" << std::endl;
      return 0.2656;
   }

   double getTheMachAndCheese(double currentSpeed, double altitude) // minus the cheese
   {
      return currentSpeed / getSpeedOfSound(altitude);
   }

   double getForceOfAirResistance(double altitude, double velocity, double area)
   {
      return -1.0 * (0.5 * getDragCoefficient(getTheMachAndCheese(
         velocity, altitude)) * getAirDensity(altitude) * (velocity * velocity
            ) * area);
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

   double computeAcceleration(double force, double weight, double gravity = 0.0)
   {
      //assert(force > 0.0);
      //assert(weight > 0.0);
      double acceleration = force / weight;


      assert(gravity <= 0.0);
      return gravity + acceleration;
   }

   double getXAcceleration
   (
      double weight, double angle, double altitude, double totalVelocity, double area
   )
   {
      //need to add drag to this
      double force = getForceOfAirResistance(altitude, totalVelocity, area);
      //std::cout << "X Air Resistance: " << getForceOfAirResistance(altitude, totalVelocity, area) * sin(angle) << std::endl;

      return computeAcceleration(force, weight);
   }

   double getYAcceleration
   (
      double weight, double angle, double altitude, double totalVelocity, double area
   )
   {
      //need to add drag to this
      double force = getForceOfAirResistance(altitude, totalVelocity, area);
      //std::cout << "Y Air Resistance: " << getForceOfAirResistance(altitude, totalVelocity, area) * cos(angle) << std::endl;
      return computeAcceleration(
         force, weight, getGravitationalForce(altitude)
      );

   }

   double getDistanceTraveled
   (
      double velocity, double acceleration, double seconds
   )
   {
      return velocity * seconds + 0.5 * acceleration * (seconds * seconds);
   }

};