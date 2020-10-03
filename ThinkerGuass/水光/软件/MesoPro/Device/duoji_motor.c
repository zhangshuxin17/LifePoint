#include "duoji_motor.h"
extern TIM_HandleTypeDef  htim2;

//one conter times  unit us
#define DUOJI_TIMER_E_CONTER_T 10



void setMoterAngle(float angle)
{
		float plus = 0;
		int timerConter = 0;
	
	  TIM_OC_InitTypeDef sConfigOC = {0};
		plus = angle * (2500 - 500) / 180 + 500;
		timerConter = plus / DUOJI_TIMER_E_CONTER_T;
			
		sConfigOC.OCMode = TIM_OCMODE_PWM1;
		sConfigOC.Pulse = timerConter;
		sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

		HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
	
	  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);		
}

