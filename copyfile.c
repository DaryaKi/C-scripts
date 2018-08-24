#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void main (int argc, char* argv[])
{
char path[40] = "/home/daryak/"; 
int fl1;
int fl2;
struct stat st1;
struct stat st2;

//full paths to the files
char pthfl1[40]; 
strcpy(pthfl1, path[40]);
char pthfl2[40]; 
strcpy(pthfl2, path[40]);
strcat(pthfl1, argv[1]);
strcat(pthfl2, argv[2]);

fl1 = open(pthfl1, "r");
fl2 = open(pthfl2, "w+");

if (fl1 == -1 || fl2 == -1) printf("Error when opening files");
else 
{
stat(pthfl1, &st1);
//stat(pthfl2, &st2);
char ch1[st1.st_size];
//char ch2[st2.st_size];

read(fl1,&ch1,st1.st_size);

for(long int i=0; i<st1.st_size; i++)
putc(ch1[i], fl2);

close(fl1);
close(fl2);
}

}
