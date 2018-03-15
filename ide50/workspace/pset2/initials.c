#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
	int len,i=0;
	string name = GetString();
	len=strlen(name);
	printf("%c", toupper(name[0]));
	for(i=0;i<len;i++)
	{
		if(name[i]==' ')
		{ 
		    printf("%c",toupper(name[i + 1])); 
            i++;
		}
	}
	printf("\n");
}