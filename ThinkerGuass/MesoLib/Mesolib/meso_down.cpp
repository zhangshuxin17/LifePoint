#include <iostream>
#include "mesodevice.h"
#include <thread>



MesoDataToDownType mesoDataToDownType;
MesoDataToUpType mesoDataToUpType;

using namespace std;


int main()
{
     Analyze analyzeD;

     analyzeD.init("/dev/ttyUSB0",115200);


     thread task1([&]()
     {
         while (true)
         {
               analyzeD.getFrame((unsigned char * )&mesoDataToDownType);
         }
     });

     thread task2([&]()
     {
         mesoDataToUpType.ErrorCode = 0;
         mesoDataToUpType.Hz = 5;
         mesoDataToUpType.InjectType = 2;
         mesoDataToUpType.iProcess = 1;
         mesoDataToUpType.IsStart = 1;
         mesoDataToUpType.luqudSpeed = 1;
         mesoDataToUpType.OpMode = 0;
         mesoDataToUpType.RfDegree = 2;
         mesoDataToUpType.TouchDegree = 2;

         while (true)
         {
            sleep(1);

            mesoDataToUpType.iProcess ++;

            if(mesoDataToUpType.iProcess > 100) mesoDataToUpType.iProcess = 0;

            analyzeD.sendFrame((unsigned char *)&mesoDataToUpType,sizeof(mesoDataToUpType));
         }
     });

    task1.join();
    task2.join();

    cout << "Hello World!" << endl;
    return 0;
}
