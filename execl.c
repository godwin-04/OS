#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
printf("PID=%d\n",getpid());
execl("/bin/ls","ls","-l",NULL);
printf("back to original");
return 0;
}
