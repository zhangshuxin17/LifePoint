
#ifndef __INTER_FACE__
#define __INTER_FACE__

#include "stm32f1xx_hal.h"

void interface_task(void);


// set para   
#define INTER_CMD_START 0

// get system info such as . version data
#define INTER_CMD_GET_INFO 1

// 
#define INTER_CMD_STOP 2

// set system working para
#define INTER_CMD_SET_PARA 3

#define INTER_CMD_TY_FRONT 4
			
#define INTER_CMD_TY_BACK 5

#endif




