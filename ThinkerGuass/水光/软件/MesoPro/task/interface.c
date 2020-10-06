#include "interface.h"
#include "cmsis_os.h"
#include "string.h"
#include "system.h"
#include "tuiye_motor.h"



extern osSemaphoreId_t myBinarySem01Handle;
extern unsigned char cmd_rec_buf[130];
static unsigned char para[128];


void callStartWithPara(meso_msg * p_meso_msg )
{
		setSystemMesoMsg(p_meso_msg);
		setSystemStart();
}


void interface_task(void)
{
	int cmd; 
	while(1)
	{
		// wati cmd
		if(osSemaphoreAcquire(myBinarySem01Handle,10) == osOK)
		{
			cmd = cmd_rec_buf[0];
			memcpy(para,cmd_rec_buf + 1,128);
		}else{
			cmd = INTER_CMD_GET_INFO;
		}	
		
		
		// get cmd
		
		switch(cmd)
		{
			case INTER_CMD_START:
					callStartWithPara((meso_msg *)para );
			break;
			case INTER_CMD_GET_INFO:
					sendSystemMsg();
			break;
			case INTER_CMD_STOP:
					setSystemStop();
			break;		
			
			case INTER_CMD_SET_PARA:
					setSystemMesoMsg((meso_msg *)para );
			break;		

			case INTER_CMD_TY_FRONT:
						goRunFast();
			break;	

			case INTER_CMD_TY_BACK:
						goBack();
			break;				
			
			default:
			break;
		}
		
		
		osDelay(1);
		
	}
	
	
}


