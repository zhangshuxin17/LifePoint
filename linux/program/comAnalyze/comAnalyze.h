#include "com.h"

typedef void (*Fcb)(unsigned char * pData, int Size);



class  Analyze 
{
	public : 
    Analyze(){pfcb_ = Analyze::defaultCallBack;};

    int init(char * pComDevice,int comBaud,Fcb pFcb); // define private callback
    int init(char * pComDevice,int comBaud);
    int sendFrame(unsigned char * pData, int size);

    // ret :size of package
    // receive Data
    int getFrame(unsigned char * pData);


	protected:
	

    static void defaultCallBack(unsigned char * pData, int Size);
    Fcb pfcb_;
	void runThread(void);
	benCom com_;
};
