void Drive()
{
	motor[leftMotor] = vexRT[Ch3] / 2;
  motor[rightMotor] = vexRT[Ch2] / 2;
}

void ArmControl()
{
	displayLCDCenteredString(0, "Verkefni 3 Is Running");
	displayLCDCenteredString(1, "Verkefni 3 Is Running");

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
    motor[armMotor] = -8;
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
