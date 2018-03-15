#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    float pay;
    int amount=0,quaters=0,dimes=0,nickels=0,pennies=0,count=0;
    printf("O hai! ");
    do
    {
     printf("How much change is owed?\n");
     pay=GetFloat();
    }while(pay<0);
    amount=round(pay*100);
    quaters=amount/25;
    amount=amount%25;
    dimes=amount/10;
    amount=amount%10;
    nickels=amount/5;
    amount=amount%5;
    pennies=amount;
    count=quaters+dimes+nickels+pennies;
    printf("%d\n",count);
}