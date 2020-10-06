#include "tuiye_motor.h"

extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim3;

void goRun(int type)
{
		// 10K  36000
	TIM_OC_InitTypeDef sConfigOC = {0};
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
		
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = type == 0 ? 3600 : 1800;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
   
  }
	
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
	

  
	
}

void goRunFast(void)
{

		// 10K  36000
	TIM_OC_InitTypeDef sConfigOC = {0};
	TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
		
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 36000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
   
  }
	
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
	

	
}



void goBack(void)
{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
	
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
	
}
