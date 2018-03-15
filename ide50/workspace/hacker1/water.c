#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int time, bottles;
    do
    {
    printf("minutes: ");
    time=GetInt();
    }while(time<=0);
    bottles=time*12;
    printf("bottles: %d\n",bottles);
  
}