#include <stdio.h>
#include <cs50.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>

int main (int argc, string argv[])
{
    int key=0,len,i,j=0,lencode;
    string code_word,text;
      
    do
    {
        if(argc!=2)
        {
            printf("Enter valid keys.\n");
            return 1;
        }
        
        else //if (isalpha(argv[1]))
        {
            code_word=argv[1];
            lencode=strlen(code_word);
            for(i=0;i<lencode;i++)
            {
                if(isalpha(code_word[i]))
                {
                    
                }
                else
                {
                    printf("Enter only alphabets as code.\n");
                    return 1;
                }
            }
            key=1;
        }
        
    }while(key!=1);
    
    text=GetString();
    len=strlen(text);
    
    for(i=0;i<len;i++)
    {
        if(isalpha(text[i]))
        {
            if(code_word[j]>='a'&&code_word[j]<='z')
            {
                if(((text[i]+(code_word[j]-97)>90)&&((text[i]>='A')&&(text[i]<='Z')))||((text[i]+(code_word[j]-97)>122)&&((text[i]>='a')&&(text[i]<='z'))))
                {
                    text[i]=text[i]+(code_word[j]-97)-26;
                    j++;
                }
                else
                {
                    text[i]=text[i]+(code_word[j]-97);
                    j++;
                }
            }
            
            else if(code_word[j]>='A'&&code_word[j]<='Z')
            {
                if(((text[i]+(code_word[j]-65)>90)&&((text[i]>='A')&&(text[i]<='Z')))||((text[i]+(code_word[j]-65)>122)&&((text[i]>='a')&&(text[i]<='z'))))
                {
                    text[i]=text[i]+(code_word[j]-65)-26;
                    j++;
                }
                else
                {
                    text[i]=text[i]+(code_word[j]-65);
                    j++;
                }
            }
            
        }
        
        if(j==lencode)
        {
            j=0;
        }
    }
    printf("%s\n",text);
    return 0;
}