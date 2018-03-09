void Stop()
{
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}

void Drive(int instructions)
{
	int state = 0;
	float rotationConstant = 1.66;
	//Forward
	if (instructions == 1)
	{
		motor[rightMotor] = 63;
		motor[leftMotor]  = 63;
		state = 1;
	}
	//Backward
	else if (instructions == 2)
	{
		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
	}
	//Turn
	else if (instructions == 3)
	{
		state = 3;

		if(SensorValue(rightEncoder) % 3 <= 1)
		{
			SensorValue[rightEncoder] = 0;
			while(SensorValue[rightEncoder] < 90 * rotationConstant)
			{
				motor[rightMotor] = -90;
				motor[leftMotor] = 90;
			}
		}
		else
		{
			SensorValue[rightEncoder] = 0;
			while(SensorValue[rightEncoder] < 90 * rotationConstant)
			{
				motor[rightMotor] = 90;
				motor[leftMotor] = -90;
			}
		}
	}
}

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
}

void ProximityAlert()
{
	int threshold = 30;
	if (SensorValue(sonar1) > threshold)
	{
		Drive(1);
	}
	else if(SensorValue(sonar1) < threshold)
	{
	  Drive(3);
	}
}
