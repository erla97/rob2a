#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Motor,  port2,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           armMotor,      tmotorServoContinuousRotation, openLoop)
#include <drive_control.c>
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{
  while(EmergencyButtons() == false)
  {
    Drive();
    ArmControl();
    ClawControl();
    EmergencyButtons();
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
