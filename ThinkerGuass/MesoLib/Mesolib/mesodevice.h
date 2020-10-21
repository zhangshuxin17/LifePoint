#ifndef MESODEVICE_H
#define MESODEVICE_H

#include "comAnalyze.h"
#include <string.h>
#include "stdio.h"
#include <cstring>
#include <vector>

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
};

#endif // MESODEVICE_H
