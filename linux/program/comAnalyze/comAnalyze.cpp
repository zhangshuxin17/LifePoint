#include "comAnalyze.h"
#include "com.h"
#include "frame.h"
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>

boost::interprocess::interprocess_semaphore m_semaphore(0);

static unsigned char s_DataBuff[1024];
static int s_size;

void Analyze::defaultCallBack(unsigned char * pData, int Size)
{
    memcpy(s_DataBuff,pData,Size);
    s_size = Size;

    m_semaphore.post();

}

int Analyze::init(char * pComDevice,int comBaud,Fcb pFcb )
{
    com_.connect(pComDevice,comBaud);

	registCb(pFcb);
	
	boost::thread* task_thread_    = new boost::thread(boost::bind(&Analyze::runThread, this));

}


int Analyze::getFrame(unsigned char * pData)
{
    m_semaphore.wait();
    memcpy(pData,s_DataBuff,s_size);
    return s_size;
}

int Analyze::init(char * pComDevice,int comBaud )
{
    com_.connect(pComDevice,comBaud);
    registCb(pfcb_);
    boost::thread* task_thread_    = new boost::thread(boost::bind(&Analyze::runThread, this));
}


int Analyze::sendFrame(unsigned char * pData, int size)
{
    unsigned char pOut[130];
    int num;

    make_frame(pData,size,pOut,&num);

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
