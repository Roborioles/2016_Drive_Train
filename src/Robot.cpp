#include "WPILib.h"
#include "CANTalon.h"
#include "Joystick.h"
#include "Compressor.h"
#include "myNewSubsystem.cpp"
#include "Solenoid.h"

class Robot: public IterativeRobot
{
private:
	//Add all objects right here
	LiveWindow *lw;
	CANTalon * right;
	CANTalon * left;
	Joystick * rightJoystick;
	Joystick * leftJoystick;
	Compressor * myCompressor;
	Solenoid * shifter1;
	// Solenoid * shifter2;
	// Solenoid * shifter3;
	// Solenoid * shifter4;
	// Solenoid * shifter5;
	// Solenoid * shifter6;
	// Solenoid * shifter7;
	// Solenoid * shifter8;
	myNewSubsystem * sub;
	bool canPress;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		myCompressor = new Compressor(1);
		right = new CANTalon(3);
		left = new CANTalon(4);
		rightJoystick = new Joystick(0);
		leftJoystick = new Joystick(1);

		shifter1 = new Solenoid(1, 1);
		//shifter2 = new Solenoid(0, 1);
		//shifter3 = new Solenoid(0, 2);
		//shifter4 = new Solenoid(0, 3);
		//shifter5 = new Solenoid(0, 4);
		//shifter6 = new Solenoid(0, 5);
		//shifter7 = new Solenoid(0, 6);
		//shifter8 = new Solenoid(0, 7);

		// start compressor
		myCompressor->SetClosedLoopControl(true);

		sub = new myNewSubsystem(left);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		//start Compressor
		myCompressor->Start();
		//shifter->Set(false);
		canPress=true;
	}

	void TeleopPeriodic()
	{
		// bool trigpressedleft=false;
		// bool trigpressed=false;
		// trigpressed = rightJoystick->GetRawButton(1);
		// trigpressedleft=leftJoystick->GetRawButton(1);
		// printf("%d",trigpressed);

		right-> Set(-1*rightJoystick->GetY()*rightJoystick->GetY()*rightJoystick->GetY());
		left -> Set(leftJoystick -> GetY()*leftJoystick->GetY()*leftJoystick->GetY() );

		// shifter1->Set(true);
		// shifter2->Set(false);
		// shifter3->Set(true);
		// shifter4->Set(false);
		// shifter5->Set(true);
		// shifter6->Set(false);
		// shifter7->Set(true);
		// shifter8->Set(false);
		// printf("Shifted true\n");
		// if(canPress && trigpressed && trigpressedleft){
		//	shifter->Set(!shifter1->Get());
		//	canPress=false;
		// }else if(!trigpressed){
		//	canPress=true;
		//}
		if (rightJoystick->GetRawButton(4)) {
			shifter1->Set(true);
		} else if (rightJoystick->GetRawButton(5)) {
			shifter1->Set(false);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

