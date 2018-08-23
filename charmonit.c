#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
void main(int argc, char* argv[]) {
int fd;
int i;
struct stat buffer;

char path[40] = "/home/daryak/";
strcat(path, argv[1]);
fd = open(path, "r");

if (fd == NULL) printf("Error");
else 
{
stat(path, &buffer);
char ch[buffer.st_size]; 
read(fd,&ch,buffer.st_size);
printf("&ld\n",buffer.st_size);

for(long int i=0; i<buffer.st_size; i++)
printf("%c", ch[i]);

fclose(fd);
}
}
