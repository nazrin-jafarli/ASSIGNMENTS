#include<stdio.h>
#include<stdio.h>
void function(char *source,char *integers,char *nonintegers);

int main()
{
	char source[]="abc123deff99!";
	char integers[256];
	char nonIntegers[256];
	function(source,integers,nonIntegers);
	printf("source %s\n",source);
	printf("integers %s\n",integers);
	printf("nonintegers %s\n",nonIntegers);
	return 0;
	
}

void function(char *source,char *integers,char *nonIntegers)
{
	int x=0,y=0;
	for(int i=0;source[i]!='\0';i++)
	{
		if(48<=source[i] && source[i]<=57)
		{
			integers[x]=source[i];
			x++;
		}
		else
		{
			nonIntegers[y]=source[i];
			y++;
		}
	}

	nonIntegers[y]='\0';
	integers[x]='\0';
}



