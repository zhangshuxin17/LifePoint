#ifndef MESODEVICE_H
#define MESODEVICE_H

#include "comAnalyze.h"
#include <string.h>
#include "stdio.h"
#include "breath.h"
#include <cstring>
#include <vector>


typedef struct MesoDataToDownType_{
unsigned char RfDegree;
unsigned char Hz;
unsigned char InjectType;
unsigned char OpMode;
unsigned char TouchDegree;
unsigned char luqudSpeed;
unsigned char IsStart;
unsigned char ManuMode;
unsigned char OnceCmd; // 0: none  1: 更换耗材
unsigned char unused[117];
}MesoDataToDownType;


// total 126

typedef struct MesoDataToUpType_{
unsigned char RfDegree;
unsigned char Hz;
unsigned char InjectType;
unsigned char OpMode;
unsigned char TouchDegree;
unsigned char luqudSpeed;
unsigned char IsStart;
unsigned char ErrorCode;
unsigned char iProcess;  // process
unsigned char replaying;
unsigned char version[16];
unsigned char unused[100];
}MesoDataToUpType;



class MesoDevice
{
public:
    MesoDevice();
    void setRF(int iDegree); // energy
    void setHZ(int iDegree);  // frequency
    void setInjectType(int iDegree); // needle specification
    void setOpMode(int Mode);  // operating mode
    void setTouch(int iDegree);  // touch degree
    void setLiquidSpeed(int iDegree);  // liquid speed
    void replayHaocai(void);  // replay haocai
    void setManuForwordMode(void);// forword
    void setManuBackMode(void);// back;
    void setNormalMode(void);// normal mode;



    void start();
    void stop();

    int getSystemState();  // start or stop
    int getProcess();    // process

    Analyze Analyze_;

    MesoDataToDownType mesoDataToDownType_;
    MesoDataToUpType mesoDataToUpType_;

    int proccess_num;
};

#endif // MESODEVICE_H
