#include "DriveUltra.h"
#include "Commands/PIDGoToTarget.h"
#include "Commands/PIDGoToTarget.cpp"

DriveUltra::DriveUltra()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

}

// Called just before this Command runs the first time
void DriveUltra::Initialize()
{
	wallLimit = 10; // get value from testing
	wallDetector->Initialize();

}

// Called repeatedly when this Command is scheduled to run
void DriveUltra::Execute()
{
	double receivedVal = wallDetector->GetRangeInches();

	if(receivedVal >= wallLimit )
	{
		PIDGoToTarget::Start(); // use data from CV camera to get to wall
	}

	else
	{
		PIDGoToTarget::Start(); // use data from CV camera to locate target area around wall
		                        // and drive to that location
  	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUltra::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveUltra::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUltra::Interrupted()
{

}
