#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
void stat_use(){
int e;
char fname[10];
struct stat p;
printf("\nEnter filename:");
scanf("%s",fname);
e=stat(fname,&p);
printf("\nProminent file details are:\n");
printf("\te: %d\n",e);
printf("\tFilename: %s\n",fname);
printf("\tPermissions: %o\n",p.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
printf("\tLinks: %ld\n",p.st_nlink);
printf("\tSize: %ld\n",p.st_size);
printf("\tGroup id:%d\n",p.st_gid);
printf("\tTime change last status: %ld",p.st_ctime);
}
void fstat_use(){
int fd,e;
char fname[10];
struct stat fp;
printf("\nEnter filename:");
scanf("%s",fname);
fd=open(fname,O_RDONLY);
e=fstat(fd,&fp);
printf("\nProminent file details are:\n");
printf("\te: %d\n",e);

printf("\tFilename: %s\n",fname);
printf("\tPermissions: %o\n",fp.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
printf("\tLinks: %ld\n",fp.st_nlink);
printf("\tSize: %ld\n",fp.st_size);
printf("\tGroup id:%d\n",fp.st_gid);
printf("\tTime change last status: %ld",fp.st_ctime);
}
int main(){
stat_use();
printf("\n");
fstat_use();
}
