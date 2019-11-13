#include "mbed.h"

DigitalOut led1(LED1);
Serial pc(USBTX, USBRX); // tx, rx

int main()
{
    while(1)
    {
        char aux = pc.getc();
        if(aux == 'h'){
            pc.printf("¡Hola!\n");
        }
    }
}
