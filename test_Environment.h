#pragma once

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
		double r0;
		double d0;
		double r1;
		double d1;
		double d;
		// exercise
		double result = getLinearInterpolation(d0, r0, d1, r1, d);
		// verify
		assert(result/* == what we want*/);
	}
	// x1 is equal to x2
	void getLinearInterpolation_testX1EqualToX2();
	// x1 is greater than x2
	void getLinearInterpolation_testX1GreaterThanX2();
	// x3 is before x1 and x2
	void getLinearInterpolation_testX3BeforeX1OrX2();
	// x3 is between x1 and x2
	void getLinearInterpolation_testX3BetweenX1OrX2();
	// x3 is after x1 and x2
	void getLinearInterpolation_testX3AfterX1OrX2();
	// x3 is equal to x1
	void getLinearInterpolation_testX3EqualsX1();
	// x3 is equal to x2
	void getLinearInterpolation_testX3EqualsX2();


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
	void getSpeedOfSound_testAltitudeIsNeg();
	void getSpeedOfSound_testAltitudeIs1000();
	void getSpeedOfSound_testAltitudeIs40000();
	void getSpeedOfSound_testAltitudeIsGreaterThan40000();
	void getSpeedOfSound_testAltitudeIs1500();
	void getSpeedOfSound_testAltitudeIs35000();


	void getGravitationalAcceleration_testAltitudeIsZero();
	void getGravitationalAcceleration_testAltitudeIsNeg();
	void getGravitationalAcceleration_testAltitudeIs1000();
	void getGravitationalAcceleration_testAltitudeIs25000();
	void getGravitationalAcceleration_testAltitudeIsGreaterThan25000();
	void getGravitationalAcceleration_testAltitudeIs1500();
	void getGravitationalAcceleration_testAltitudeIs22500();


	void getAirDensity_testAltitudeIsZero();
	void getAirDensity_testAltitudeIsNeg();
	void getAirDensity_testAltitudeIs1000();
	void getAirDensity_testAltitudeIs80000();
	void getAirDensity_testAltitudeIsGreaterThan80000();
	void getAirDensity_testAltitudeIs1500();
	void getAirDensity_testAltitudeIs75000();


	void getDragCoefficient_testMachIsPoint3();
	void getDragCoefficient_testMachIsLessThanPoint3();
	void getDragCoefficient_testMachIsNeg();
	void getDragCoefficient_testMachIsPoint5();
	void getDragCoefficient_testMachIs5();
	void getDragCoefficient_testMachIsGreaterThan5();
	void getDragCoefficient_testMachIsPoint4();
	void getDragCoefficient_testMachIs3Point945();


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