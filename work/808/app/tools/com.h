#include "ros/ros.h"
#include <vector>
#include <iostream>
#include <string>
#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <sstream>
#include <semaphore.h>
#include <malloc.h>
#include <stdbool.h>
#include <vector>


class benCom 
{
	public : 
	
	u_int32_t getTermBaudBitmap(u_int32_t baud);
	int connect(const char * port_path, u_int32_t baudrate);
	int  sendData(const unsigned char * data, size_t size);
	int getData(unsigned char * data, size_t size);
	benCom();
	
	protected:
	
	int serial_fd;
	
	
};
