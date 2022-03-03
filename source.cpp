#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <map>

#define DEBUG

const double mass = 46.7; // kg
const double area = 0.018842; // m^2
const double initVelocity = 827.0; // m/s

// Doesn't call other functions

double convertDegreesToRadians(double degrees)
{
  const double pi = 3.14159265358979323846;
  return (2 * pi * degrees) / 360;
}

double getLinearInterpolation(double v1, double c1, double v0, double c0, double v)
{
  if (v1 == v)
    return c1;
  return c0 + ((v - v0) * (c1 - c0)) / (v1 - v0);
}

// Does call other functions

// Tables -------------------------------------->

double getSoundSpeed(double altitude) // temp
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
  if (soundSpeedTable.find(altitude) != soundSpeedTable.end())
     return soundSpeedTable.at(altitude);
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
  std::cout << "getSpeedOfSound: Altitude is a bit too high" << std::endl;
  assert(false); // our value is too big
     
     
  return 324.0;
}

double getDragCoefficient(double mach) // temp
{
  // do linear interpolation on value above the mach and value below the mach
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
  if (machTable.find(mach) != machTable.end())
     return machTable.at(mach);
  double keys[] = { 0.300,0.500,0.700,0.890,0.920,
     0.960,0.980,1.000,1.020,1.060,1.240,1.530,
     1.990,2.870,2.890,5.000 };
  
  double prev = 0.300;
  for (double key : keys)
  {
     if (mach <= key)
     {
        return getLinearInterpolation(
           key, machTable.at(key), prev,
           machTable.at(prev), mach);
     }
     prev = key;
  }
  std::cout << "getDragCoefficient: Mach is a bit too high" << std::endl;
  assert(false); // our value is too big
  return 0.2656;
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
  if (airDensityTable.find(altitude) != airDensityTable.end())
     return airDensityTable.at(altitude);
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
  std::cout << "getAirDensity: Altitude is a bit too high" << std::endl;
  assert(false); // our value is too big

  return 0.0000185;
}

double getGravitationalAcceleration(double altitude)
{
  std::map<double, double> gravityTable({
     { 0,	   -9.807 },
     { 1000,  -9.804 },
     { 2000,  -9.801 },
     { 3000,  -9.797 },
     { 4000,  -9.794 },
     { 5000,  -9.791 },
     { 6000,  -9.788 },
     { 7000,  -9.785 },
     { 8000,  -9.782 },
     { 9000,  -9.779 },
     { 10000, -9.776 },
     { 15000, -9.761 },
     { 20000, -9.745 },
     { 25000, -9.730 }
  });
  if (gravityTable.find(altitude) != gravityTable.end())
     return gravityTable.at(altitude);
  double keys[] = { 0,1000,2000,3000,4000,5000,6000,
     7000,8000,9000,10000,15000,20000,25000 };
  double prev = 0;
  for (double key : keys)
  {
     if (altitude <= key)
     {
        return getLinearInterpolation(
           key, gravityTable.at(key), prev,
           gravityTable.at(prev), altitude);
     }
     prev = key;
  }
  std::cout << "getGravitationalForce: Altitude is a bit too high" << std::endl;
  assert(false); // our value is too big
  return -9.73;
}
// <---------------------------------------------

double getMach(double velocity, double altitude)
{
  // velocity / speed of sound
  return velocity / getSoundSpeed(altitude);
}


double getForce(double velocity, double altitude)
{
  // 1/2 * coefficient of drag * density of the air * velocity squared * area
  return 0.5 * getDragCoefficient(getMach(velocity, altitude)) * getAirDensity(altitude) * (velocity * velocity) * area;
}

double getAcceleration(double velocity, double altitude, double mass)
{
  // force / mass
  return getForce(velocity, altitude) / mass;
}

double getDX(double angle, double velocity)
{
  // sin(angle) * velocity
  return sin(angle) * velocity;
}

double getDY(double angle, double velocity)
{
  // cos(angle) * velocity
  return cos(angle) * velocity;
}

double getDDX(double angle, double velocity, double altitude, double mass)
{
  // -1 * sin(angle) * acceleration
  return -1 * sin(angle) * getAcceleration(velocity, altitude, mass);
}

double getDDY(double altitude, double angle, double velocity, double mass)
{
  // gravitational acceleration - cos(angle) * acceleration
  return getGravitationalAcceleration(altitude) - cos(angle) * getAcceleration(velocity, altitude, mass);
}

double updateX(double xPos, double angle, double velocity, double time, double altitude, double mass)
{
  // last position of x + last DX * time + 1/2 DDX * time^2 
  return xPos + getDX(angle, velocity) * time + 0.5 * getDDX(angle, velocity, altitude, mass) * (time * time);
}

double updateY(double yPos, double angle, double velocity, double time, double altitude, double mass)
{
  // last position of y + last DY * time + 1/2 DDY * time^2
  return yPos + getDY(angle, velocity) * time + 0.5 * getDDY(altitude, angle, velocity, mass) * (time * time);
}


double updateDX(double angle, double velocity, double altitude, double mass, double time)
{
  // last DX + DDX * time
  return getDX(angle, velocity) + getDDX(angle, velocity, altitude, mass) * time;
}

double updateDY(double angle, double velocity, double altitude, double mass, double time)
{
  // last DY + DDY * time
  return getDY(angle, velocity) + getDDY(altitude, angle, velocity, mass) * time;
}





double getTotalXDistanceTraveled(double degAngle, double initVelocity)
{
  /*
   * seconds <-- 0.0
   * 
   * radAngle = degToRad(degAngle)
   * 
   * xpos <-- 0.0
   * ypos <-- 0.0
   * DO
   *    update velocity
   *    update angle
   *    update xpos
   *    update ypos
   * WHILE ypos > 0.0
   */
  double intervals = 1.0;

  double velocity = initVelocity;

  double seconds = 0.0;

  double radAngle = convertDegreesToRadians(degAngle);

  double xPos = 0.0;
  double yPos = 0.0;

  double prevVelocity;
  double prevX;
  double prevY;

  double dx;
  double dy;
  do
  {
     prevVelocity = velocity;
     prevX = xPos;
     prevY = yPos;

     dx = updateDX(radAngle, prevVelocity, prevY, mass, intervals);
     dy = updateDY(radAngle, prevVelocity, prevY, mass, intervals);
     velocity = sqrt(dx * dx + dy * dy);

     xPos = updateX(prevX, radAngle, prevVelocity, intervals, prevY, mass);
     yPos = updateY(prevY, radAngle, prevVelocity, intervals, prevY, mass);
     radAngle = atan(dx / dy);
     std::cout << seconds << "\tVelocity: " << velocity << "\t( " << xPos << ", " << yPos << " )" << std::endl;

     seconds += intervals;
  } while (yPos > 0.0);
  return 0.0;
}

int main()
{
  getTotalXDistanceTraveled(30.0, 827.0);
}