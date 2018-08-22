//Input from keyboard, output to the file
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//#include<io.h>

void main(int argc, char* argv[], char *envp[])
{
FILE *Fdl;
struct stat buffer;

Fdl = fopen("/home/daryak/charput.txt", "w+");

if(Fdl == NULL) 
printf("Error when creating/opening the file");
else
{
for(int j=1; j<=argc; j++)
{
stat(argv[j], &buffer);
char ch[buffer.st_size] = argv[j];
for (long i = 0; i<buffer.st_size; i++)
{
putc((int)ch[i],Fdl);
//if (write(Fdl,buffer,buffer.st_size) != buffer.st_size)
//printf("Error");
}
}
fclose(Fdl);
}

}
