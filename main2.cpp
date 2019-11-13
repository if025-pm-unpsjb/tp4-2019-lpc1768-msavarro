#include "mbed.h"

DigitalOut leds[] =
  { (LED1), (LED2), (LED3), (LED4) };
Serial pc (USBTX, USBRX); // tx, rx

int
main ()
{
  char aux = 1;
  int index = 0;
  while (1)
    {
      if (pc.readable ())
        {
          aux = pc.getc ();
          index = aux - '0';
        }
      pc.printf ("%d", index);
      if (index > 0 && index < 5)
        {
          leds[index - 1] = 1;
          wait (0.25);
          leds[index - 1] = 0;
          wait (0.25);
        }
    }
}
