#include <cs50.h>
#include <stdio.h>

void sort(int values[] ,int n)
{
    int min,j;
    for(int i=0; i<n; i++)
    {
        min=values[i];
        if(min<values[i-1])
        {
            for( j=i-1;values[j]>min;j--)
            {
                values[j+1]=values[j];
            }
            values[j+1]=min;
        }
        
        
    }
    
    for(int i=0;i<n;i++)
        {
            printf("%i\n",values[i]);
        }
}

int main(void)
{
    int n,values[20];
    n=GetInt();
     for(int i=0;i<n;i++)
    {
        values[i]=GetInt();
    }
    sort(values,n);
    return 0;
   
}
