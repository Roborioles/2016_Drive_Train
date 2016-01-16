#include "WPILib.h"
#include "CANTalon.h"
#include "Joystick.h"
#include "Compressor.h"

class myNewSubsystem
{
public:
	myNewSubsystem(CANTalon * exampleTalon)
	{
		left = exampleTalon;

	}
	~myNewSubsystem()
	{

	}

	void driveLeft(float leftDrive)
	{
		left->Set(leftDrive);
	}

private:
	CANTalon * left;

};


