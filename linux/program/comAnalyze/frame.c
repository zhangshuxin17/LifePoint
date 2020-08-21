#include "crc16.h"
#include "frame.h"
#include "stdio.h"
#include "string.h"


/*

获取串口数据 帧格式为 固定长途为  131字节 aa 55  cmd data crc



*/





enum{
CMD_HEADERAA = 0, // 头部
CMD_HEADER55 = 1, // 头部
CMD_BODY
};

static int cmd_state = CMD_HEADERAA;
static int cmd_pos = 0;
static unsigned char cmd_rec_buf[130];


static comFcb s_Fcb;


void registCb(comFcb pFcb)
{
    s_Fcb = pFcb;
}

static unsigned char cmd_send_buf[130];
void make_frame(unsigned char *pData, int size, unsigned char *pOutData, int *pNum)
{
    unsigned short Crc;

    memset(cmd_send_buf,0,sizeof(cmd_send_buf));

    cmd_send_buf[0] = 0xAA;
    cmd_send_buf[1] = 0x55;
    memcpy(cmd_send_buf + 2,pData,size);

    CRC16(cmd_send_buf,size + 2,&Crc);

    cmd_send_buf[128] = Crc >> 8;
    cmd_send_buf[129] = Crc >> 8;

   memcpy(pOutData,cmd_send_buf,130);

    *pNum = 130;


}

void cmd_handle(unsigned short data)
{
	
	if(cmd_state == CMD_HEADERAA){
		
		if(data == 0xaa) cmd_state = CMD_HEADER55;

	}
	else if(cmd_state == CMD_HEADER55)
	{
				if(data == 0x55)
				{
						cmd_state = CMD_BODY;
					  cmd_pos = 0;
				} else
				{
						cmd_state = CMD_HEADERAA;
				}
		
	}else if(cmd_state == CMD_BODY)
	{
			cmd_rec_buf[cmd_pos] = data;
		  cmd_pos++;
			if(cmd_pos >= 129){ // get now frame
						// checkcrc
			  unsigned short wCrc;
			  CRC16(cmd_rec_buf,128,&wCrc);
				s_Fcb(cmd_rec_buf,129);
				//osSemaphoreRelease(myBinarySem01Handle);
				cmd_state = CMD_HEADERAA;
			}
	}else
	{
			cmd_state = CMD_HEADERAA;
	}

}

