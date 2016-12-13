#include "TestNoSensors.h"

TestNoSensors::TestNoSensors() :
	left(new Talon(1)), right(new Talon(0))
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void TestNoSensors::Initialize()
{
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void TestNoSensors::Execute()
{
	left->SetSpeed(0.5);
	right->SetSpeed(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool TestNoSensors::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void TestNoSensors::End()
{
	left->SetSpeed(0);
	right->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestNoSensors::Interrupted()
{

}
