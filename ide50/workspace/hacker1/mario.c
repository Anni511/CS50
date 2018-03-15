#include<stdio.h>
#include<cs50.h>

int main (void)
{
    int high,i,j,k,l;
    do
    {
    printf("Height: ");
    high=GetInt();
    }while(high<0||high>23);
    
        for(i=0; i<high; i++)
        {
            for(j=0; j<high-1-i; j++)
            {
                printf(" ");
            }
            
            for(k=high-i-1; k<high; k++)
            {
                printf("#");
            }
            
            printf("  ");
            
            for(l=0; l<i+1; l++)
            {
                printf("#");
            }
            
            printf("\n");
        }
    
}