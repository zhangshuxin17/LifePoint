#ifndef MESODEVICE_H
#define MESODEVICE_H

#include "comAnalyze.h"
#include <string.h>
#include "stdio.h"
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
}MesoDataToDownType;




typedef struct MesoDataToUpType_{
unsigned char RfDegree;
unsigned char Hz;
unsigned char InjectType;
unsigned char OpMode;
unsigned char TouchDegree;
unsigned char luqudSpeed;
unsigned char IsStart;
unsigned char ErrorCode;
unsigned char iProcess;
}MesoDataToUpType;



class MesoDevice
{
public:
    MesoDevice();
    void setRF(int iDegree);
    void setHZ(int iDegree);
    void setInjectType(int iDegree);
    void setOpMode(int Mode);
    void setTouch(int iDegree);
    void setLiquidSpeed(int iDegree);
    void start();
    void stop();
    int getSystemState();

    Analyze Analyze_;
    MesoDataToDownType mesoDataToDownType_;
};

#endif // MESODEVICE_H
