#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
main(int argc,char *argv[])
{
int f;
printf("Value of arguments: %d",argc-1);
for(int i = 0; i<argc-1;i++){
f = mkdir(argv[i+1], 0777);
if(f == -1)
{
printf("\nCannot create a directory");
exit(-1);
}
