#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

#include<sys/types.h>
int main(){
char fname[10],pat[10],temp[1024];
char *newline;
FILE *fp;
printf("\nEnter file name:");
scanf("%s",fname);
printf("\nEnter pattern to search for:");
scanf("%s",pat);
fp=fopen(fname,"r");
printf("file opened");
while(fgets(temp,1000,fp)!=NULL){
if(newline=strstr(temp,"\n"))
*newline='\0';
if(strstr(temp,pat)!=NULL){
printf("\n%s found in file\n",pat);
}
}
}
