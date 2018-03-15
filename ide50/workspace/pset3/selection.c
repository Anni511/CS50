#include <cs50.h>
#include <stdio.h>

void sort(int values[] ,int n)
{
    int pos,temp;
    for(int i=0; i<n; i++)
    {
        int min=values[i];
        pos=i;
        for(int j=i; j<n; j++)
        {
            if(values[j]<min)
            {
                min=values[j];
                pos=j;
            }
        }
        temp=values[i];
        values[pos]=temp;
        values[i]=min;
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

