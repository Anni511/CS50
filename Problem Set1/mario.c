#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int i,j,h,k;
    do
    {
    printf("height: ");
    h=GetInt();
    }while(h<0||h>23);
    
        for(i=0;i<h;i++)
        {
            for(j=0;j<h-i-1;j++)
            {
            printf(" ");
            }
            for(k=j;k<=h;k++)
            {
            printf("#");
            }
        printf("\n");
        }
    
}