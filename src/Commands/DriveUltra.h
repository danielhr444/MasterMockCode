#ifndef DriveUltra_H
#define DriveUltra_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Commands/PIDGoToTarget.h"
#include "Commands/PIDGoToTarget.cpp"

class DriveUltra: public CommandBase
{
public:
	DriveUltra();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Ultrasonic* wallDetector;
	double wallLimit;


};

#endif
