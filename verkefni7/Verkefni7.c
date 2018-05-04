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

int lightSensorSens = 400
int SonarDist = 42

/*-----------------------------------------------------------------------------------------------------------------*\
|*                                         		 	  - Verkefni 7 -                                          	 			 *|
|*                                      		 ROBOTC on VEX 2.0 CORTEX                                       		   *|
|*                                                                                                     						 *|
|*                                      			- Cleaning the Table -                                               *|
|*                                                                                                     						 *|
|*                                                                                                     						 *|
|*  The Vex will use his brush to clean Eirikurs floors. A simple ai will rotate based on how close the sensor is. *|
|* A simple ai will rotate based on how close the sensor is. when the laps have finished he will change directions.*|
\*-----------------------------------------------------------------------------------------------------------------*/



//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	while(EmergencyButtons() == false)
  {
  	if (SensorValue[lightSensor] < lightSensorSens)
    {

    	SensorValue[rightEncoder] = 0;
			SensorValue[leftEncoder] = 0;

    	if (SensorValue[sonar1] > 42)
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
