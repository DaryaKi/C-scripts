#include <stdlib.h>
#include <stdio.h>

void main(int argc, char* argv[]) 
{
FILE *fp;

if((fp=fopen("sequence.txt","w")) != NULL)
{
	for(int i=1; i<argc; i++)
	{
	fprintf(fp, "%s ", argv[i]);
	printf("%s ", argv[i]);
	}
fclose(fp);
}

else printf("Error when creating or opening file");
}
