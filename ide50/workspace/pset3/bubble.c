#include <cs50.h>
#include <stdio.h>
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(values[i]>values[i+1])
            {
                temp=values[i+1];
                values[i+1]=values[i];
                values[i]=temp;
            }
            
        }
    }    
        for(int i=0;i<n;i++)
        {
            printf("%i\n",values[i]);
        }
    
    return;
}
int main (void)
{
    int values[20],n;
    n=GetInt();
    for(int i=0;i<n;i++)
    {
        values[i]=GetInt();
    }
    sort(values,n);
    return 0;
    
}