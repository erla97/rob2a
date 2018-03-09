int threshold = 2800;
int throttle = 65;
int state = 0;

void Linefollow()
{
  if(SensorValue(lineFollower2) < threshold)
  {
    // go straight
    motor[leftMotor]  = throttle;
    motor[rightMotor] = throttle;
    state = 0;
  }
 	if(SensorValue(lineFollower1) < threshold)
  {
    // counter-steer right:
    motor[leftMotor]  = -30;
    motor[rightMotor] = throttle;
    state = 1;
  }
  if(SensorValue(lineFollower3) < threshold)
  {
    // counter-steer left:
    motor[leftMotor]  = throttle;
    motor[rightMotor] = -30;
    state = 2;
  }
}

void Linefind()
{
	if(state == 1)
	{
 		motor[leftMotor]  = -throttle;
    motor[rightMotor] = throttle;
	}
	if(state == 2)
	{
		motor[leftMotor]  = throttle;
    motor[rightMotor] = -throttle;
	}
}

void DisplayValues()
{
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollower1));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollower2));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollower3));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
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
