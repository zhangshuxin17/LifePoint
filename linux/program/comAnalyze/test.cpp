#include "comAnalyze.h"

Fcb pFcb ;

int main(int arg , char *argv[])
{
	Analyze  analyze;

    analyze.init("/dev/ttyUSB0",115200,pFcb);


    while(1);
	
return 0;	

}
