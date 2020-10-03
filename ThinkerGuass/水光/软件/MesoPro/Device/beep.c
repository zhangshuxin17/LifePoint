#include "beep.h"

void setBeepState(int on_off)
{
	on_off == 0 ? HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET): HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
}
