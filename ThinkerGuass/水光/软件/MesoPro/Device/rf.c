#include "rf.h"

extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim4;


void setRF(int degree )
{
  TIM_OC_InitTypeDef sConfigOC = {0};
  
  if(degree == 0) return ;

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = degree / 10 * 10000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {

  }
  
  
  
   sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 36;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
  
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
   
  }
 	
	
	
}



