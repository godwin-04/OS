#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
printf("PID=%d\n",getpid());
char *args[]={"ls","-l",NULL};
execv("/bin/ls",args);
printf("back to original");
return 0;
}
