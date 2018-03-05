#pragma config(Sensor, dgtl10, leftEncoder,    sensorRotation)
#pragma config(Sensor, dgtl12, rightEncoder,   sensorRotation)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorServoContinuousRotation, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                                 - Moving Straight with Encoders -                                  *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program implements a self-straightening algorithm that provides a higher power level to the  *|
|*  motor that has traveled less, determined by comparing the values of the two encoders.             *|
|*  In this project we use eulerangles combined with an increment that drives the vex forward and back*|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

float dist = 235;

void Drive(int increment, bool backforw)
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	while(dist * increment > SensorValue[rightEncoder])
	{
		int i = (backforw) ? (1):(-1);

		if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = 80 * i;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 80 * i;		    // Left Motor is run at power level 80
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = 60 * i;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 80 * i;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = 80 * i;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 60 * i;		    // Left Motor is run at power level 60
		}
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;

	for (int i = 1; i < 5; i++)
	{
		Drive(i,true);
		Drive(i,false);
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
