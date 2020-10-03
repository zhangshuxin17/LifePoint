#include "buttom.h"

int getButtomState(void)
{
	int retVel = BUTTON_PRESSED;
	
	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5) == GPIO_PIN_RESET)
	{
			retVel = BUTTON_PRESSED;
	}else{
			retVel = BUTTON_RELEASED;
	}
			
	return retVel;
}


