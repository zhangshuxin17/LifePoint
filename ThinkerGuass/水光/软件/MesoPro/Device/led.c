#include "led.h"

void setLedState(int on_off)
{
	on_off == 0 ? HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_RESET): HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_SET);
}
