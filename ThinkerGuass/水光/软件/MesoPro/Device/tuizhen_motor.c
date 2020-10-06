#include "tuizhen_motor.h"

extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim3;

void TIM3_set_para(int frec , int plus)
{

	if(frec == 0) return ;
	

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 7200 ;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = (10000 - 1) / frec;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
   
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = htim3.Init.Period / 2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {

  }
 
}


void setTuizhenMotorPara(int frec, int degree )
{
	
	// 10K  36000
	  TIM_OC_InitTypeDef sConfigOC = {0};

		degree = degree > 99 ? 99 : degree;
		
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 36000 / (100 - degree);
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
   
  }
	
	TIM3_set_para(frec,0);

	
}

