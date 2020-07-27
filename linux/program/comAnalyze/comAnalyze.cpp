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

void Analyze::runThread(void)
{
	while(1)
	{
	


	}
}
