#include "mbed.h"

PwmOut led (LED1);
DigitalOut led4 (LED4);

Serial pc (USBTX, USBRX); // tx, rx
float intensidad = 0.00f;
float subida = 0.10f;
int retardoSubida = 1;

void
aumentar ()
{
  led.write (intensidad);
  wait (retardoSubida);
  intensidad += subida;
}

void
disminuir ()
{
  led.write (intensidad);
  wait (retardoSubida);
  intensidad -= subida;
}

int
main ()
{

  while (1)
    {
      while (intensidad < 1.00f)
        {
          led4 = 0;
          aumentar ();
        }
      while(intensidad > 0.0f){
          led4 = 1;
          disminuir ();
        }
    }
}

