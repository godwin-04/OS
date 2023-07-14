#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
char buf1[]="LAB ";
char buf2[]="OS Linux";
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
int main(void){
int fd;
if((fd=creat("f3.txt",0666))<0){
perror("Creation error");
exit(1);

}
if(write(fd,buf1,sizeof(buf1))<0){
perror("Writing error");
exit(2);
}
if(lseek(fd,4096,SEEK_SET)<0){
perror("Positioning error");
exit(3);
}
if(write(fd,buf2,sizeof(buf2))<0){
perror("Writing error");
exit(2);
}
}
