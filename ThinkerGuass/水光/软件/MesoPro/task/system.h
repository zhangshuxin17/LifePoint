
#ifndef __INTER_SYSTEM__
#define __INTER_SYSTEM__

#include "stm32f1xx_hal.h"

typedef struct meso_msg_t{
unsigned char ucRfDegree;
unsigned char ucEMSDegree;
unsigned char ucWorkingFrec;
unsigned char ucTouchDegree;
unsigned char ucInjectorType;
unsigned char ucJuceSpeed; // chu ye sudu
unsigned char ucWorkingMode;
	

}meso_msg;


// ucWorkingMode
enum{
	
KEY_MODE_KEEP = 0,
KEY_MODE_CLIKED = 1
};







void system_task(void);



void setSystemMesoMsg(meso_msg * p_meso_msg );

void setSystemStop(void);

void setSystemStart(void);

void sendSystemMsg(void);



#endif




