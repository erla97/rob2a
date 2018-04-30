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
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
	{
		// Move Forward
		motor[rightMotor] = 90;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 90;		    // Left Motor is run at power level 80
	}
	else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
	{
		// Turn slightly right
		motor[rightMotor] = 60;		    // Right Motor is run at power level 60
		motor[leftMotor]  = 90;		    // Left Motor is run at power level 80
	}
	else	// Only runs if leftEncoder has counted more encoder counts
	{
		// Turn slightly left
		motor[rightMotor] = 90;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 60;		    // Left Motor is run at power level 60
	}
}

void Turn()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	if(DirectionR == false)
	{
		while(SensorValue[rightEncoder] < 570)
		{
			motor[rightMotor] = 90;
			motor[leftMotor] = -30;
		}
	}
	else
	{
		while(SensorValue[leftEncoder] < 570)
		{
			motor[rightMotor] = -30;
			motor[leftMotor] = 90;
		}
	}
	if(DirectionR == false)
	{
		DirectionR = true;
	}
	else
	{
		DirectionR = false;
	}
}
