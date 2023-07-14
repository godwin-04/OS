#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int pid=vfork();
int sum=0;
if(pid==0){
for(int i=1;i<=10;i++){
sum+=i;
}
printf("\nsum=%d (sum from 1 to 10 from child)\n",sum);
exit(0);
}
else{
for(int i=11;i<=20;i++){
sum+=i;
}
printf("\nsum=%d (sum from 11 to 20 from parent)\n",sum);
}
return 0;
}
