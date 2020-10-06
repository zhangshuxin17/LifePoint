#include "system.h"
#include "cmsis_os.h"
#include "string.h"
#include "buttom.h"
#include "duoji_motor.h"
#include "tuiye_motor.h"
#include "tuizhen_motor.h"
#include "rf.h"
#include "ems.h"



static meso_msg s_meso_msg;

static int s_system_start_flag = 0;
static int v_key_state = 0;
static int runing_state = 0;

int IsWorkingStart(void)
{
	if(s_meso_msg.ucWorkingMode == KEY_MODE_KEEP)
	{
			return getButtomState();
	}
	else
	{
		static int s_old_keyState = 0;
		
		// check  rase adge
		
		if((getButtomState() == BUTTON_PRESSED) && (s_old_keyState == BUTTON_RELEASED))
		{		
			v_key_state = v_key_state == 0 ? 1 : 0;
		}
		
		s_old_keyState = getButtomState();
		
		return v_key_state;
	}
	
}

void system_task(void)
{

	while(1)
	{
		// checking starting
		if(IsWorkingStart() && (s_system_start_flag == 1))
		{
				runing_state = 1;
		}
		else
		{
			if(runing_state == 1) runing_state = 2;
		}
		
		
		
		
		// machine state
		
		if(runing_state == 0) // wait cmd
		{
		
		
		}else if(runing_state == 1) // runing
		{
				setMoterAngle(s_meso_msg.ucTouchDegree);
			  setTuizhenMotorPara(s_meso_msg.ucWorkingFrec,s_meso_msg.ucTouchDegree);
				goRun(s_meso_msg.ucInjectorType);
				setRF(s_meso_msg.ucRfDegree);
				setEMS(s_meso_msg.ucEMSDegree);
		
		}else if(runing_state == 2) // pause
		{
			v_key_state = 0;
			
			setMoterAngle(0);
			setTuizhenMotorPara(0,0);
			goRun(0);
			setRF(0);
			setEMS(0);
			runing_state = 0;

		}else{
		
			runing_state = 0;
		}
		
		
		osDelay(10);
		
	}
}



void setSystemMesoMsg(meso_msg * p_meso_msg )
{
		s_meso_msg = * p_meso_msg;
}


void setSystemStop(void)
{
		s_system_start_flag = 0;
}

void setSystemStart(void)
{
		s_system_start_flag = 1;
}


void sendSystemMsg(void)
{

}

