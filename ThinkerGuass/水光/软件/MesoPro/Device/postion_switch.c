#include "postion_switch.h"


int getPosSwitchState(void)
{
	int retVel = SWITCH_PRESSED;
	
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13) == GPIO_PIN_RESET)
	{
			retVel = SWITCH_PRESSED;
	}else{
			retVel = SWITCH_RELEASED;
	}
			
	return retVel;
}
