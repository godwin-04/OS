#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main(){
int fd1,fd2,sz1,sz2;
char c;
fd1=open("p3.txt",O_RDONLY);
sz1=lseek(fd1,-1,SEEK_END);
char s[sz1];
lseek(fd1,0,SEEK_SET);
fd2=open("p3_2.txt",O_WRONLY|O_CREAT,0777);
read(fd1,s,sz1);
write(fd2,s,sz1);
close(fd1);
close(fd2);

printf("\nfile1:\n%s",s);
fd2=open("p3_2.txt",O_RDONLY);
sz2=lseek(fd2,0,SEEK_END);
char s2[sz2];
lseek(fd1,0,SEEK_SET);
read(fd2,s2,sz1);
printf("\nfile2:\n%s",s2);
close(fd2);
}
