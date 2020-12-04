#ifndef MESO_GPIO_H
#define MESO_GPIO_H


typedef struct s_initGpiotag_{
char * pGrop;
int num;
int in_out;
}s_initGpio;




void gpios_init(s_initGpio sgpio[] ,int nums);


// pGrop GPIOA,GPIOB,GPIOC,GPIOD,GPIOE
// pin num 0 - 31
// value : if in_out is 0, 
void gpio_set_value(char * pGrop,int num,int value);

int gpio_get_value(char * pGrop,int num);


#endif // MESO_GPIO_H
