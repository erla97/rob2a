int Laps = 0;
int Turns = 0;
int TurnDegrees = 643;
bool DirectionR = false;

bool EmergencyButtons()
{
	if(vexRT[Btn8U] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	if(vexRT[Btn8U] == 1)
	{
		return true;
	}
}

void Stop()
{
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}

void Drive()
{

	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
	{
		// Move Forward
		motor[rightMotor] = 91;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 90;		    // Left Motor is run at power level 80
	}
	else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
	{
		// Turn slightly right
		motor[rightMotor] = 0;		    // Right Motor is run at power level 60
		motor[leftMotor]  = 90;		    // Left Motor is run at power level 80
	}
	else	// Only runs if leftEncoder has counted more encoder counts
	{
		// Turn slightly left
		motor[rightMotor] = 90;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 0;		    // Left Motor is run at power level 60
	}
}

void Turn()
{
		//Avoid being Stuck
	if(Laps > Turns && DirectionR == false)
	{
		DirectionR = true;
		Laps = 0;
	}
	else if(Laps > Turns && DirectionR == true)
	{
		DirectionR = false;
		Laps = 0;
	}
	Laps += 1;

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	if(DirectionR == false)
	{
		while(SensorValue[rightEncoder] < TurnDegrees)
		{
			motor[rightMotor] = 90;
			motor[leftMotor] = -30;
		}
	}
	else
	{
		while(SensorValue[leftEncoder] < TurnDegrees)
		{
			motor[rightMotor] = -30;
			motor[leftMotor] = 90;
		}
	}

	//Change Directions
	if(DirectionR == false)
	{
		DirectionR = true;
	}
	else
	{
		DirectionR = false;
	}



}
