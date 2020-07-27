#include "com.h"


benCom::benCom()
{
	serial_fd = -1;
}


u_int32_t benCom::getTermBaudBitmap(u_int32_t baud)
{
    #define BAUD_CONV( _baud_) case _baud_:  return B##_baud_
    switch (baud) {
        BAUD_CONV(1200);
        BAUD_CONV(1800);
        BAUD_CONV(2400);
        BAUD_CONV(4800);
        BAUD_CONV(9600);
        BAUD_CONV(19200);
        BAUD_CONV(38400);
        BAUD_CONV(57600);
        BAUD_CONV(115200);
        BAUD_CONV(230400);
        BAUD_CONV(460800);
        BAUD_CONV(500000);
        BAUD_CONV(576000);
        BAUD_CONV(921600);
        BAUD_CONV(1000000);
        BAUD_CONV(1152000);
        BAUD_CONV(1500000);
        BAUD_CONV(2000000);
        BAUD_CONV(2500000);
        BAUD_CONV(3000000);
        BAUD_CONV(3500000);
        BAUD_CONV(4000000);
    }
    return -1;
}

int benCom::connect(const char * port_path, u_int32_t baudrate)
{

    {
        if (serial_fd != -1) {
            close(serial_fd);
        }
	
        serial_fd = open(port_path, O_RDWR | O_NOCTTY | O_NDELAY);
        if (serial_fd == -1) {
			printf("error open \n");
            return -1;
        }

        struct termios options, oldopt;
        tcgetattr(serial_fd, &oldopt);
        bzero(&options,sizeof(struct termios));

        u_int32_t termbaud = getTermBaudBitmap(baudrate);
        if (termbaud == (u_int32_t)-1) {
            if (serial_fd != -1) {
                close(serial_fd);
            }
            serial_fd = -1;
			printf("error getTermBaudBitmap \n");
            return -1;
        }
        cfsetispeed(&options, termbaud);
        cfsetospeed(&options, termbaud);

        options.c_cflag |= (CLOCAL | CREAD);
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;
        options.c_iflag &= ~(IXON | IXOFF | IXANY);
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
        options.c_oflag &= ~OPOST;
		

		options.c_cc[VMIN]  = 20;
		options.c_cc[VTIME] = 10;

        tcflush(serial_fd,TCIFLUSH);
        if (fcntl(serial_fd, F_SETFL, 0)) {
            if (serial_fd != -1) {
                close(serial_fd);
            }
			printf("error tcflush \n");
            serial_fd = -1;
            return -1;
        }
        if (tcsetattr(serial_fd, TCSANOW, &options)) {
            if (serial_fd != -1) {
				printf("error tcsetattr \n");
                close(serial_fd);
            }
            serial_fd = -1;
            return -1;
        }

        u_int32_t dtr_bit = TIOCM_DTR;
        ioctl(serial_fd, TIOCMBIC, &dtr_bit);
    }

     
    return serial_fd;
}



int  benCom::sendData(const unsigned char * data, size_t size)
{

    if (data == NULL || size ==0) {
        return 0;
    }

    size_t tx_len = 0;
    do {
        int ans = write(serial_fd, data + tx_len, size-tx_len);
        if (ans == -1) {
            return tx_len;
        }
        tx_len += ans;
    }while (tx_len<size);

    return tx_len;
}

int benCom::getData(unsigned char * data, size_t size)
{

    int ans = read(serial_fd, data, size);
    return ans;
}

