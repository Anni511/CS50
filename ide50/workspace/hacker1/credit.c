#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long int no;
    no=GetLongLong();
    int sum=0;
    int x=0,y=0,z=0,t=0;
    for(long long int j=no;j>0;j=j/100)
    {
        sum=sum+(j%10);
    }
    
    for(long long int k=no/10;k>0;k=k/100)
    {
        if((2*(k%10))>=10)
        {
            sum=sum+((2*(k%10))%10)+(2*(k%10))/10;
        }
        else
        sum=sum+2*(k%10);       
    }

    if(sum%10==0)
    {
        x = no/pow(10,13);
        y=no/pow(10,14);
        z=no/pow(10,15);
        t=no/pow(10,12);
       if(x==34||x==37)
        {
            printf("AMEX\n");
        }
       else if(y==51||y==52||y==53||y==54||y==55)
        {
            printf("MASTERCARD\n");
        }
        else if(t==4||z==4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}