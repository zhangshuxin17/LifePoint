#include "mesodevice.h"


MesoDevice::MesoDevice()
{
    Analyze_.init("/dev/ttyUSB0",115200);
}


void MesoDevice::setRF(int iDegree)
{
  //  Analyze_.sendFrame()
}
void MesoDevice::setHZ(int iDegree)
{

}
void MesoDevice::setInjectType(int iDegree)
{

}
void MesoDevice::setOpMode(int Mode)
{

}
void MesoDevice::setTouch(int iDegree)
{

}
void MesoDevice::setLiquidSpeed(int iDegree)
{

}
void MesoDevice::start()
{


}
void MesoDevice::stop()
{


}

int MesoDevice::getSystemState()
{

        return 0;
}
