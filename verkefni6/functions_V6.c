int threshold = 2300;
int throttle = 60;
int state = 0;

bool cot = false;
bool clawOpenClosed = false;

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

void Linefollow()
{

			if(SensorValue(lineFollower1) < threshold)
			{
			  // counter-steer right:
			  motor[rightMotor] = throttle;
			  motor[leftMotor] = -throttle / 2;

			}

			if(SensorValue(lineFollower3) < threshold)
			{
			  // counter-steer left:
			  motor[leftMotor]  = throttle;
			  motor[rightMotor] = -throttle / 2;

			}

}

void GrabAndTwist()
{
	if(cot != true)
	{
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	motor[clawMotor] = -127;
	wait1Msec(1490);
	motor[clawMotor] = 0;
	motor[leftMotor] = 127;
	motor[rightMotor] = -127;
	wait1Msec(1000);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	wait1Msec(2500);
	cot = true;
 }
 else
 {
  motor[armMotor] = 127;
  wait1Msec(760);
  motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	motor[armMotor] = 0;
  motor[clawMotor] = 127;
	wait1Msec(1400);
	motor[clawMotor] = 0;
	wait1Msec(1300);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	wait1Msec(2500);
 }
}

void Stop()
{
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}
