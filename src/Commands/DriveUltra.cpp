#include "DriveUltra.h"
#include "Commands/PIDGoToTarget.h"
#include "Commands/PIDGoToTarget.cpp"

DriveUltra::DriveUltra()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(DriveTrain);

}

// Called just before this Command runs the first time
void DriveUltra::Initialize()
{
	wallLimit = 10; // get value from testing
	wallDetector->Initialize();
	motorTurn->resetGyro();
	motorTurn->resetEncoders();

	PIDGoToTarget::Start(); // moves robot to wall, use CV camera to find wall

}

// Called repeatedly when this Command is scheduled to run
void DriveUltra::Execute()

{
	// i have no idea what would go here
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUltra::IsFinished()
{
	double receivedVal = wallDetector->GetRangeInches();

	if (receivedVal <= wallLimit)
	{
		PIDGoToTarget::Start(); // Use CV camera to set goal as the wall with targets
		return true;            // PID method will stop once close enough
	}
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
