#include "comAnalyze.h"
#include <string.h>
#include "stdio.h"
#include <cstring>
#include <vector>




int main(int arg , char *argv[])
{

	Analyze  analyze;

    analyze.init("/dev/ttyUSB0",115200);


    while(1)
    {

        std::string mss;
        char bss[128];
        gets(bss);

        std::vector<std::string> cmd;

        std::stringstream ss(bss);

        std::string cmd_t;

        while(ss >> cmd_t){ cmd.push_back(cmd_t);}

        if(cmd.at(0) == "ready"){

            analyze.sendFrame((unsigned char *)"ready",4);


        }else if(cmd.at(0) == "standby"){


            analyze.sendFrame((unsigned char *)"standby",4);

        }




    }

	
return 0;	

}
