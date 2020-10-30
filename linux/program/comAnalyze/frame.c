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

#define FRAME_SIZE 130

static int cmd_state = CMD_HEADERAA;
static int cmd_pos = 0;
static unsigned char cmd_rec_buf[FRAME_SIZE + 20];


static comFcb s_Fcb;


void registCb(comFcb pFcb)
{
    s_Fcb = pFcb;
}

static unsigned char cmd_send_buf[FRAME_SIZE];
void make_frame(unsigned char *pData, int size, unsigned char *pOutData, int *pNum)
{
    unsigned short Crc;

    memset(cmd_send_buf,0,sizeof(cmd_send_buf));

    cmd_send_buf[0] = 0xAA;
    cmd_send_buf[1] = 0x55;
    memcpy(cmd_send_buf + 2,pData,size);

    CRC16(cmd_send_buf + 2,FRAME_SIZE - 4,&Crc);

    cmd_send_buf[FRAME_SIZE - 2] = Crc &0xFF;
    cmd_send_buf[FRAME_SIZE - 1] = Crc >> 8;

   memcpy(pOutData,cmd_send_buf,FRAME_SIZE);

    *pNum = FRAME_SIZE;


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
            if(cmd_pos >= (FRAME_SIZE - 2)){ // get now frame
						// checkcrc
			  unsigned short wCrc;
              unsigned short wRecvCrc = cmd_rec_buf[FRAME_SIZE - 2 -2 ] + cmd_rec_buf[FRAME_SIZE - 2 -1] * 256;
              CRC16(cmd_rec_buf,FRAME_SIZE - 4,&wCrc);
              if(wCrc == wRecvCrc)
              {
                s_Fcb(cmd_rec_buf,FRAME_SIZE - 4);
              }
				//osSemaphoreRelease(myBinarySem01Handle);
				cmd_state = CMD_HEADERAA;
			}
	}else
	{
			cmd_state = CMD_HEADERAA;
	}

}

