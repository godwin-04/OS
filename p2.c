#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main()
{
int c,fd,sz;
char c1[11];
int a=1;
//read-0,write-1,display error-2 files
//Owner,Group,User default 770 gives permission to 777 for user 111-read write display
while(a){
printf("\n1. create\n2. open\n3. close\n4. read\n5. write\n6. unlink\n7.lseek and reverse\n8.
exit\n");
printf("enter your choice: ");
scanf("%d",&c);
switch(c){
case(1):
fd=open("f1.txt",O_CREAT,0777);
printf("fd=%d\n",fd);
break;
case(2):fd=open("f1.txt",O_RDONLY);//file descriptor
printf("fd=%d\n",fd);
printf("sz=%d\n",sz);
close(fd);
break;
case(3):
close(fd);
printf("fd=%d\n",fd);
break;
case(4):

fd=open("f1.txt",O_RDONLY);//file descriptor
sz=read(fd,c1,10);
puts(c1);
printf("fd=%d\n",fd);
printf("sz=%d\n",sz);
close(fd);
break;
case(5):
fd=open("f1.txt",O_WRONLY|O_CREAT,0777);//file descriptor
sz=write(fd,"hi,hello\n",strlen("hi,hello\n"));
printf("fd=%d\n",fd);
printf("sz=%d\n",sz);
close(fd);
break;
case(6):
sz=unlink("f1.txt");
printf("sz=%d\n",sz);
break;
case(7):
fd=open("f1.txt",O_RDONLY);
sz=lseek(fd,-1,SEEK_END);//-1 --> we go to second last char
printf("sz=%d\n",sz);
char s;
for(int i=0;i<=sz+1;i++){
read(fd,&s,1);
printf("%c",s);
lseek(fd,-(i+1),SEEK_END);
}
close(fd);
break;
case(8):
a=0;
break;
default:
printf("invalid input\n");
}}

return 0;
}
