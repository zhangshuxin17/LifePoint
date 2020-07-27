#include "comAnalyze.h"
#include "com.h"
#include "frame.h"
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>


int Analyze::init(char * pComDevice,int comBaud,Fcb pFcb )
{
	com_.connect(pComDevice,comBaud);

	registCb(pFcb);
	
	boost::thread* task_thread_    = new boost::thread(boost::bind(&Analyze::runThread, this));

}


int Analyze::sendFrame(unsigned char code,unsigned char * pData, int size)
{
    unsigned char * pOut = NULL;
    int num;

    make_frame(code,pData,size,pOut,&num);

    return com_.sendData(pOut,num);
}

void Analyze::runThread(void)
{
	while(1)
	{
        unsigned char data;
	
        if(com_.getData(&data,1) == 1)
            cmd_handle(data);

	}
}
