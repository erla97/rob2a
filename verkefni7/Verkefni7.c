#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    lineFollower1,  sensorLineFollower)
#pragma config(Sensor, in2,    lineFollower2,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollower3,  sensorLineFollower)
#pragma config(Sensor, in4,    lightSensor,    sensorReflection)
#pragma config(Sensor, in8,    potentioMeter,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  touch,          sensorTouch)
#pragma config(Sensor, dgtl2,  sonar1,         sensorSONAR_cm)
#pragma config(Sensor, dgtl10, leftEncoder,    sensorRotation)
#pragma config(Sensor, dgtl12, rightEncoder,   sensorRotation)
#pragma config(Motor,  port2,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           armMotor,      tmotorServoContinuousRotation, openLoop, reversed)

#include <functions_V7.c>

/*-----------------------------------------------------------------------------------------------------*\
|*                                         	 - Verkefni 7 -                                          	 *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                       *|
|*                                                                                                     *|
|*  The vex only starts once one of the linefollowers detect a value above 2800. vex then follows      *|
|* that value and if it goes of course it will automaticly rotate towards the angle that lost the line *|
\*-----------------------------------------------------------------------------------------------------*/



//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	while(EmergencyButtons() == false)
  {
  	if (SensorValue[lightSensor] < 400)
    {
    	SensorValue[rightEncoder] = 0;
			SensorValue[leftEncoder] = 0;

    	if (SensorValue[sonar1] > 38)
    	{
    		Drive();
    	}
    	else
    	{
    		Turn();
    	}
    }
  }
}
