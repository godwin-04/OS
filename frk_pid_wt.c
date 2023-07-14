#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int pid=fork();
int sum=0;
if(pid==0){
printf("\nprinting from child process:");
printf("\nchild process id=%d",getpid());
printf("\nparent process id=%d",getppid());
for(int i=1;i<=10;i++){
sum+=i;
}
printf("\nsum=%d (sum from 1 to 10 from child)\n",sum);
}
else{
for(int i=11;i<=20;i++){
sum+=i;
}
sleep(5);
printf("\nprinting from parent process:");
printf("\nparent process id=%d",getpid());
printf("\nsum=%d (sum from 11 to 20 from parent)\n",sum);
wait(NULL);
}
return 0;
}
