#include <iostream>
#include "mesodevice.h"
#include <thread>
#include "stdlib.h"

using namespace std;


int main()
{
    MesoDevice mesoDevice;


    thread task1([&]()
    {
        while (true)
        {
            std::string mss;
            char bss[128];
            gets(bss);

            std::vector<std::string> cmd;

            std::stringstream ss(bss);

            std::string cmd_t;

            while(ss >> cmd_t){ cmd.push_back(cmd_t);}

            if(cmd.at(0) == "hz"){

                mesoDevice.setHZ(stoi(cmd.at(1).c_str()));

            }else if(cmd.at(0) == "rf"){
                 mesoDevice.setRF(stoi(cmd.at(1).c_str()));
            }else if(cmd.at(0) == "touch"){
                mesoDevice.setTouch(stoi(cmd.at(1).c_str()));
           }else if(cmd.at(0) == "opmode"){
                mesoDevice.setOpMode(stoi(cmd.at(1).c_str()));
           }else if(cmd.at(0) == "type"){
                mesoDevice.setInjectType(stoi(cmd.at(1).c_str()));
           }else if(cmd.at(0) == "speed"){
                mesoDevice.setLiquidSpeed(stoi(cmd.at(1).c_str()));
           }

        }
    });

    thread task2([&]()
    {

        while (true)
        {
           printf("isStart = %d  Process = %d \n", mesoDevice.getSystemState(),mesoDevice.getProcess());

        }
    });

   task1.join();
   task2.join();

   cout << "Hello World!" << endl;
   return 0;



    return 0;
}
