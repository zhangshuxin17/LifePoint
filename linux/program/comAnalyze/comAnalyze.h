#include "com.h"

typedef void (*Fcb)(unsigned char * pData, int *pSize);



class  Analyze 
{
	public : 
	Analyze(){};

	int init(char * pComDevice,int comBaud,Fcb pFcb);
    int sendFrame(unsigned char code,unsigned char * pData, int size);
	protected:
	
    Fcb pfcb_;
	void runThread(void);
	benCom com_;
};
