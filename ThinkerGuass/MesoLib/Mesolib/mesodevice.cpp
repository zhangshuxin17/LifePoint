#include "mesodevice.h"




MesoDevice::MesoDevice()
{
    Analyze_.init("/dev/pts/20",115200);

    mesoDataToDownType_.Hz = 5;
    mesoDataToDownType_.InjectType = 1;
    mesoDataToDownType_.IsStart = 0;
    mesoDataToDownType_.OpMode = 0;
    mesoDataToDownType_.RfDegree = 1;
    mesoDataToDownType_.TouchDegree = 1;
    mesoDataToDownType_.luqudSpeed = 1;
    mesoDataToDownType_.ManuMode = 0;
    mesoDataToDownType_.OnceCmd = 0;
    proccess_num = 0;
    startBreath_slow();
}

void MesoDevice::replayHaocai(void)  // replay haocai
{
    mesoDataToDownType_.IsStart = 0;
    mesoDataToDownType_.OnceCmd = 1;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}

void MesoDevice::setManuForwordMode(void)// forword
{
    mesoDataToDownType_.IsStart = 0;
    mesoDataToDownType_.ManuMode = 1;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));

}

void MesoDevice::setManuBackMode(void)// back;
{
    mesoDataToDownType_.IsStart = 0;
    mesoDataToDownType_.ManuMode = 2;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
}

void MesoDevice::setNormalMode(void)
{
    mesoDataToDownType_.OnceCmd = 0;
    mesoDataToDownType_.ManuMode = 0;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
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
    mesoDataToDownType_.OnceCmd = 0;
    mesoDataToDownType_.ManuMode = 0;
    mesoDataToDownType_.IsStart = 1;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
    startBreath_fast();
}
void MesoDevice::stop()
{
    mesoDataToDownType_.IsStart = 0;
    mesoDataToDownType_.OnceCmd = 0;
    mesoDataToDownType_.ManuMode = 0;
    Analyze_.sendFrame((unsigned char *)&mesoDataToDownType_,sizeof(mesoDataToDownType_));
    startBreath_slow();

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
