#pragma once

class TestForce
{
public:
	void run()
	{
		operatorDivMass_testDivByZero();
		operatorDivMass_testZeroForcePosMass();
		operatorDivMass_testZeroForceNegMass();
		operatorDivMass_testPosForceZeroMass();
		operatorDivMass_testNegForceZeroMass();
		operatorDivMass_testNegForcePosMass();
		operatorDivMass_testPosForceNegMass();
		operatorDivMass_testNegForceNegMass();
		operatorDivMass_testPosForcePosMass();
		operatorDivMass_testBothZero();

		operatorDivAcceleration_testDivByZero();
		operatorDivAcceleration_testDivByZero();
		operatorDivAcceleration_testZeroForcePosAcc();
		operatorDivAcceleration_testZeroForceNegAcc();
		operatorDivAcceleration_testPosForceZeroAcc();
		operatorDivAcceleration_testNegForceZeroAcc();
		operatorDivAcceleration_testNegForcePosAcc();
		operatorDivAcceleration_testPosForceNegAcc();
		operatorDivAcceleration_testNegForceNegAcc();
		operatorDivAcceleration_testPosForcePosAcc();
		operatorDivAcceleration_testBothZero();
	}
private:
	void operatorDivMass_testDivByZero();
	void operatorDivMass_testZeroForcePosMass();
	void operatorDivMass_testZeroForceNegMass();
	void operatorDivMass_testPosForceZeroMass();
	void operatorDivMass_testNegForceZeroMass();
	void operatorDivMass_testNegForcePosMass();
	void operatorDivMass_testPosForceNegMass();
	void operatorDivMass_testNegForceNegMass();
	void operatorDivMass_testPosForcePosMass();
	void operatorDivMass_testBothZero();


	void operatorDivAcceleration_testDivByZero();
	void operatorDivAcceleration_testDivByZero();
	void operatorDivAcceleration_testZeroForcePosAcc();
	void operatorDivAcceleration_testZeroForceNegAcc();
	void operatorDivAcceleration_testPosForceZeroAcc();
	void operatorDivAcceleration_testNegForceZeroAcc();
	void operatorDivAcceleration_testNegForcePosAcc();
	void operatorDivAcceleration_testPosForceNegAcc();
	void operatorDivAcceleration_testNegForceNegAcc();
	void operatorDivAcceleration_testPosForcePosAcc();
	void operatorDivAcceleration_testBothZero();
};