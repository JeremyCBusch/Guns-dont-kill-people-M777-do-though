#pragma once

#include "environment.h"
#include <cassert>

class TestEnvironment
{
public:
	void run()
	{
		// TODO: Jeremy
		getLinearInterpolation_testX1LowerThanX2();
		getLinearInterpolation_testX1EqualToX2();
		getLinearInterpolation_testX1GreaterThanX2();
		getLinearInterpolation_testX3BeforeX1OrX2();
		getLinearInterpolation_testX3BetweenX1OrX2();
		getLinearInterpolation_testX3AfterX1OrX2();
		getLinearInterpolation_testX3EqualsX1();
		getLinearInterpolation_testX3EqualsX2();


		getSpeedOfSound_testAltitudeIsZero();
		getSpeedOfSound_testAltitudeIsNeg();
		getSpeedOfSound_testAltitudeIs1000();
		getSpeedOfSound_testAltitudeIs40000();
		getSpeedOfSound_testAltitudeIsGreaterThan40000();
		getSpeedOfSound_testAltitudeIs1500();
		getSpeedOfSound_testAltitudeIs35000();


		getGravitationalAcceleration_testAltitudeIsZero();
		getGravitationalAcceleration_testAltitudeIsNeg();
		getGravitationalAcceleration_testAltitudeIs1000();
		getGravitationalAcceleration_testAltitudeIs25000();
		getGravitationalAcceleration_testAltitudeIsGreaterThan25000();
		getGravitationalAcceleration_testAltitudeIs1500();
		getGravitationalAcceleration_testAltitudeIs22500();


		getAirDensity_testAltitudeIsZero();
		getAirDensity_testAltitudeIsNeg();
		getAirDensity_testAltitudeIs1000();
		getAirDensity_testAltitudeIs80000();
		getAirDensity_testAltitudeIsGreaterThan80000();
		getAirDensity_testAltitudeIs1500();
		getAirDensity_testAltitudeIs75000();


		getDragCoefficient_testMachIsPoint3();
		getDragCoefficient_testMachIsLessThanPoint3();
		getDragCoefficient_testMachIsNeg();
		getDragCoefficient_testMachIsPoint5();
		getDragCoefficient_testMachIs5();
		getDragCoefficient_testMachIsGreaterThan5();
		getDragCoefficient_testMachIsPoint4();
		getDragCoefficient_testMachIs3Point945();

		// TODO: Jacob
		getForceOfAirResistance_testPosVelocityPosAltitude();
		getForceOfAirResistance_testZeroVelocityPosAltitude();
		getForceOfAirResistance_testNegVelocityPosAltitude();
		getForceOfAirResistance_testPosVelocZeroAltitude();
		getForceOfAirResistance_testZeroVelocityZeroAltitude();
		getForceOfAirResistance_testNegVelocityZeroAltitude();
		getForceOfAirResistance_testPosVelocityNegAltitude();
		getForceOfAirResistance_testZeroVelocityNegAltitude();
		getForceOfAirResistance_testNegVelocityNegAltitude();
		getForceOfAirResistance_testSuperHighAltitude();
		getForceOfAirResistance_testSuperHighVelocity();


		getMach_testVelocityIsNeg();
		getMach_testVelocityIsPos();
		getMach_testVelocityIsZero();


		update_testProjectileFired();
		update_testProjectileUnfired();


		reset_test();


		draw_test();
	}
private:
	// x1, y1, x2, y2, x3
	// x1 is lower than x2
	void getLinearInterpolation_testX1LowerThanX2()
	{
		// setup
		Environment env;
		double d0 = 0;
		double r0 = 1.225;
		double d1 = 1000;
		double r1 = 1.112;
		double d = 200;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.2024);
	}  // teardown

	// x1 is equal to x2
	void getLinearInterpolation_testX1EqualToX2()
	{
		// setup
		Environment env;
		double d0 = 0;
		double r0 = 1.225;
		double d1 = 0;
		double r1 = 1.225;
		double d = 200;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.225);
	}  // teardown

	// x1 is greater than x2
	void getLinearInterpolation_testX1GreaterThanX2()
	{
		// setup
		Environment env;
		double d0 = 1000;
		double r0 = 1.112;
		double d1 = 0;
		double r1 = 1.225;
		double d = 200;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.2024);
	}  // teardown

	// x3 is before x1 and x2
	void getLinearInterpolation_testX3BeforeX1OrX2()
	{
		// setup
		Environment env;
		double d0 = 200;
		double r0 = 1.2024;
		double d1 = 1000;
		double r1 = 1.112;
		double d = 0;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.2024);
	}  // teardown

	// x3 is between x1 and x2
	// void getLinearInterpolation_testX3BetweenX1OrX2();	// this test case is redundant
	

	// x3 is after x1 and x2
	void getLinearInterpolation_testX3AfterX1OrX2()
	{
		// setup
		Environment env;
		double d0 = 0;
		double r0 = 1.225;
		double d1 = 200;
		double r1 = 1.2024;
		double d = 1000;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.225);
	}  // teardown

	// x3 is equal to x1
	void getLinearInterpolation_testX3EqualsX1()
	{
		// setup
		Environment env;
		double d0 = 0.0;
		double r0 = 1.225;
		double d1 = 1000;
		double r1 = 1.112;
		double d = 0.0;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.225);
	}  // teardown

	// x3 is equal to x2
	void getLinearInterpolation_testX3EqualsX2()
	{
		// setup
		Environment env;
		double d0 = 0.0;
		double r0 = 1.225;
		double d1 = 1000;
		double r1 = 1.112;
		double d = 1000.0;
		// exercise
		double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result == 1.112);
	}  // teardown


	void getSpeedOfSound_testAltitudeIsZero()
	{
		// setup
		Environment env;
		double altitude = 0.0;
		// exercise
		double result = env.getSpeedOfSound(altitude);
		// verify
		assert(result == 340.0);
	}  // teardown
	
	void getSpeedOfSound_testAltitudeIs1000()
		{
			// setup
			Environment env;
			double altitude = 1000.0;
			// exercise
			double result = env.getSpeedOfSound(altitude);
			// verify
			assert(result == 336.0);
		}  // teardown

	void getSpeedOfSound_testAltitudeIs40000()
	{
		// setup
		Environment env;
		double altitude = 40000.0;
		// exercise
		double result = env.getSpeedOfSound(altitude);
		// verify
		assert(result == 324.0);
	}  // teardown
	void getSpeedOfSound_testAltitudeIsGreaterThan40000()
	{
		// setup
		Environment env;
		double altitude = 40001.0;
		// exercise
		double result = env.getSpeedOfSound(altitude);
		// verify
		assert(result == 324.0);
	}  // teardown
	void getSpeedOfSound_testAltitudeIs1500()
	{
		// setup
		Environment env;
		double altitude = 1500.0;
		// exercise
		double result = env.getSpeedOfSound(altitude);
		// verify
		assert(result == 334.0);
	}  // teardown
	void getSpeedOfSound_testAltitudeIs35000()
	{
		// setup
		Environment env;
		double altitude = 3500.0;
		// exercise
		double result = env.getSpeedOfSound(altitude);
		// verify
		assert(result == 326.0);
	}  // teardown


	// get gravitational acceleration

	void getGravitationalAcceleration_testAltitudeIsZero()
	{
		// setup
		Environment env;
		double altitude = 0.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.807);
	}  // teardown

	void getGravitationalAcceleration_testAltitudeIsNeg()
	{
		// setup
		Environment env;
		double altitude = -1.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.807);
	}  // teardown

	void getGravitationalAcceleration_testAltitudeIs1000()
	{
		// setup
		Environment env;
		double altitude = 1000.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.804);
	}  // teardown

	void getGravitationalAcceleration_testAltitudeIs25000()
	{
		// setup
		Environment env;
		double altitude = 25000.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.730);
	}  // teardown

	void getGravitationalAcceleration_testAltitudeIsGreaterThan25000()
	{
		// setup
		Environment env;
		double altitude = 25000.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.730);
	}  // teardown

	void getGravitationalAcceleration_testAltitudeIs1500()
	{
		// setup
		Environment env;
		double altitude = 1500.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.8025);
	}  // teardown

	void getGravitationalAcceleration_testAltitudeIs22500()
	{
		// setup
		Environment env;
		double altitude = 22500.0;
		// exercise
		double result = env.getGravitationalAcceleration(altitude);
		// verify
		assert(result == 9.7375);
	}  // teardown




	// get air density

	void getAirDensity_testAltitudeIsZero()
	{
		// setup
		Environment env;
		double altitude = 0.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == 1.2250);
	}  // teardown

	void getAirDensity_testAltitudeIsNeg()
	{
		// setup
		Environment env;
		double altitude = -1.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == 1.2250);
	}  // teardown

	void getAirDensity_testAltitudeIs1000()
	{
		// setup
		Environment env;
		double altitude = 1000.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == 1.112);
	}  // teardown

	void getAirDensity_testAltitudeIs80000()
	{
		// setup
		Environment env;
		double altitude = 80000.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == 0.0000185);
	}  // teardown

	void getAirDensity_testAltitudeIsGreaterThan80000()
	{
		// setup
		Environment env;
		double altitude = 80001.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == 0.0000185);
	}  // teardown

	void getAirDensity_testAltitudeIs1500()
	{
		// setup
		Environment env;
		double altitude = 1500.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == 1.0595);
	}  // teardown

	void getAirDensity_testAltitudeIs75000()
	{
		// setup
		Environment env;
		double altitude = 75000.0;
		// exercise
		double result = env.getAirDensity(altitude);
		// verify
		assert(result == .00005065);
	}  // teardown


	
	//get drag coefficient

	void getDragCoefficient_testMachIsPoint3()
	{
		// setup
		Environment env;
		double mach = .300;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .1629);
	}  // teardown

	void getDragCoefficient_testMachIsLessThanPoint3()
	{
		// setup
		Environment env;
		double mach = .200;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .1629);
	}  // teardown

	void getDragCoefficient_testMachIsNeg()
	{
		// setup
		Environment env;
		double mach = -.300;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .1629);
	}  // teardown

	void getDragCoefficient_testMachIsPoint5()
	{
		// setup
		Environment env;
		double mach = .500;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .1659);
	}  // teardown

	void getDragCoefficient_testMachIs5()
	{
		// setup
		Environment env;
		double mach = 5.0;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .2656);
	}  // teardown

	void getDragCoefficient_testMachIsGreaterThan5()
	{
		// setup
		Environment env;
		double mach = 5.1;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .2656);
	}  // teardown

	void getDragCoefficient_testMachIsPoint4()
	{
		// setup
		Environment env;
		double mach = .4;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .1644);
	}  // teardown

	void getDragCoefficient_testMachIs3Point940()
	{
		// setup
		Environment env;
		double mach = .940;
		// exercise
		double result = env.getDragCoefficient(mach);
		// verify
		assert(result == .31485);
	}  // teardown


	// above is jeremys stuff ^

	// bellow this is jacobs work


	void getForceOfAirResistance_testPosVelocityPosAltitude();
	void getForceOfAirResistance_testZeroVelocityPosAltitude();
	void getForceOfAirResistance_testNegVelocityPosAltitude();
	void getForceOfAirResistance_testPosVelocZeroAltitude();
	void getForceOfAirResistance_testZeroVelocityZeroAltitude();
	void getForceOfAirResistance_testNegVelocityZeroAltitude();
	void getForceOfAirResistance_testPosVelocityNegAltitude();
	void getForceOfAirResistance_testZeroVelocityNegAltitude();
	void getForceOfAirResistance_testNegVelocityNegAltitude();
	void getForceOfAirResistance_testSuperHighAltitude();
	void getForceOfAirResistance_testSuperHighVelocity();


	void getMach_testVelocityIsNeg();
	void getMach_testVelocityIsPos();
	void getMach_testVelocityIsZero();


	void update_testProjectileFired();
	void update_testProjectileUnfired(); 


	void reset_test();


	void draw_test();
};