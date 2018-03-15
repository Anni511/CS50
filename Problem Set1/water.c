#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int time, bottles;
    printf("minutes: ");
    time=GetInt();
    bottles=time*12;
    printf("bottles: %d\n",bottles);
  
}