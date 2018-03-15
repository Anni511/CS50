#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>

int main (int argc, string argv[])
{
    int k,len,access=0;
    do
    {
        if (argc !=2)
        {
            printf("Enter valid key.\n");
            return 1;
        }
        
        else
        {
         k=atoi(argv[1]);
            access=1;
        }
        
    }while(access!=1);
    
    k=k%26;
    string word = GetString();
    len= strlen(word);
    for (int i=0;i<len;i++)
    {
       if((word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z'))
        {
            if(word[i]+k>90&&(word[i]<91&&word[i]>64))
            {
                word[i]= word[i]+k-26;
            }
            else if(word[i]+k>122&&(word[i]<123&&word[i]>96))
            {
                word[i]= word[i]+k-26;
            }
            else
            {
                word[i]=word[i]+k;
            }
        }
    }
    printf("%s\n",word);
    return 0;
}