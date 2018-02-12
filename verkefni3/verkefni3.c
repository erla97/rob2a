#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                                    				Verkefni 3                           					          *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                     Hofundar: Erla og Hrafnkell                                    *|
|*                                                                                                    *|
|*  I thessu verkefni er forritad fjarstyringuna, snudarnir a fjarstyringunni eru til thess ad hreyfa *|
|*  robotinn. Takkarnir 6D og 6U hreyfa arminn upp og nidur. Takkarnir 5D og 5U opna klonna og loka.  *|
|*                                                                                                    *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
|*		Motor - Port 4          armMotor             VEX Motor           Arm motor											*|
|*		Motor - Port 5					clawMotor						 VEX Motor					 Claw motor											*|
\*----------------------------------------------------------------------------------------------------*/

void Drive()
{
	motor[leftMotor] = vexRT[Ch3] / 2;
  motor[rightMotor] = vexRT[Ch2] / 2;
}

void ArmControl()
{
	if(vexRT[Btn6U] == 1)
  {
    motor[armMotor] = -40;
  }
  else if(vexRT[Btn6D] == 1)
  {
    motor[armMotor] = 40;
  }
  else
  {
    motor[armMotor] = 0;
  }
}

void ClawControl()
{
	if(vexRT[Btn5U] == 1)
  {
    motor[clawMotor] = 40;
  }
  else if(vexRT[Btn5D] == 1)
  {
    motor[clawMotor] = -40;
  }
  else
  {
    motor[clawMotor] = 0;
  }
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{
  while(1 == 1)
  {
    Drive();
    ArmControl();
    ClawControl();
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
