#include "gpio.h"
#include <string>
#include <sstream>
#include <iostream>
#include "stdlib.h"
#include "string.h"


static int _getGrop(char * pGrop)
{
    std::string str;
    str = pGrop;

    int ret = 0;

    if(str == "GPIOA"){
        ret = 0;
    }else if(str == "GPIOB"){
        ret = 1;
    }else if(str == "GPIOC"){
        ret = 2;
    }else if(str == "GPIOD"){
        ret = 3;
    }else if(str == "GPIOE"){
        ret = 4;
    }else{

    }

    return ret;
}

void gpios_init(s_initGpio sgpio[], int nums)
{

    for(int i = 0; i < nums; i ++){
	    int grop = _getGrop(sgpio[i].pGrop);

        std::string str;
        std::string tmp = std::to_string(grop * 32 + sgpio[i].num);
        str = "echo " + tmp + " > /sys/class/gpio/export";
	    system(str.c_str());

        if(sgpio[i].in_out)
             str = "echo out > /system/class/gpio/gpio" + tmp + "/driction";
        else
             str = "echo in > /system/class/gpio/gpio" + tmp + "/driction";

        system(str.c_str());

    }




}


// pGrop GPIOA,GPIOB,GPIOC,GPIOD,GPIOE
// pin num 0 - 31
// value : if in_out is 0, 
void gpio_set_value(char * pGrop,int num,int value)
{
  int grop = _getGrop(pGrop);

  std::string ns = std::to_string(grop * 32 + num);

  std::string str;

 if(value == 1)
    str = "echo 1 > /sys/class/gpio/gpio" + ns + "/value";
 else
    str = "echo 0 > /sys/class/gpio/gpio" + ns + "/value";

   system(str.c_str());

}

int gpio_get_value(char * pGrop,int num)
{
    int grop = _getGrop(pGrop);

    char result[128];

    std::string ns = std::to_string(grop * 32 + num);

    std::string str;


      str = "cat /sys/class/gpio/gpio" + ns + "/value";

     FILE* fp = NULL;

     if ((fp = popen(str.c_str(), "r")) != NULL)
     {
             memset(result,sizeof (result),0);
             fgets(result, sizeof(result), fp);
             pclose(fp);
     }

     int ret = result[0] - 0x30;



    return ret;

}






