/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    /*for(int i=0 ; i<n ; i++)
        {
            if(values[i]==value)
            {
                return true;
            }
        }
    return false;*///LINEAR SEARCH
     sort(values,n);
     int beg=0,end=n-1;
     do
     {
         int mid=(beg+end)/2;
         if(value>values[mid])
            {
                beg=beg+1;
            }
        
         if(value<values[mid])
            {
                end=end-1;
            }
        if(values[mid]==value)
            {
                return true;
            }
        else
            {
                return false;
            }
     }while(beg<=end);
    }
/**
 * Sorts array of n values.
 */
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
    return;
}