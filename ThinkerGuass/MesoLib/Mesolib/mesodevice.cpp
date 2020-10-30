#include "mesodevice.h"




MesoDevice::MesoDevice()
{
    Analyze_.init("/dev/pts/2",115200);

    mesoDataToDownType_.Hz = 5;
    mesoDataToDownType_.InjectType = 1;
    mesoDataToDownType_.IsStart = 0;
    mesoDataToDownType_.OpMode = 0;
    mesoDataToDownType_.RfDegree = 1;
    mesoDataToDownType_.TouchDegree = 1;
    mesoDataToDownType_.luqudSpeed = 1;

    proccess_num = 0;
}


void MesoDevice::setRF(int iDegree)
{
    mesoDataToDownType_.RfDegree = iDegree;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::setHZ(int iDegree)
{
    mesoDataToDownType_.Hz = iDegree;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::setInjectType(int iDegree)
{
    mesoDataToDownType_.InjectType = iDegree;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::setOpMode(int Mode)
{
    mesoDataToDownType_.OpMode = Mode;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::setTouch(int iDegree)
{
    mesoDataToDownType_.TouchDegree = iDegree;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::setLiquidSpeed(int iDegree)
{
    mesoDataToDownType_.luqudSpeed = iDegree;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::start()
{

    mesoDataToDownType_.IsStart = 1;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}
void MesoDevice::stop()
{
    mesoDataToDownType_.IsStart = 0;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));

}

int MesoDevice::getSystemState()
{
    Analyze_.getFrame((unsigned char *)&mesoDataToUpType_);
    proccess_num = mesoDataToUpType_.iProcess;
    return mesoDataToUpType_.IsStart;
}

int MesoDevice::getProcess(){
    return proccess_num;
}
