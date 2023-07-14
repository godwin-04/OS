#include <stdio.h>
struct Process{
int at;
int pid;
int bt;
int wt;
int tat;
int priority;
};
int TotalBurstTimes(struct Process *a){
int sum = 0;
for(int i=0;i<5;i++){
sum+=a[i].bt;
}
return sum;
}
int main()
{
struct Process a[6];
a[0].pid=1;
a[0].at=0;
a[0].bt=4;
a[0].wt=-1;
a[0].tat=-1;
a[0].priority = 2;
a[1].pid=2;
a[1].at=1;
a[1].bt=5;
a[1].wt=-1;
a[1].tat=-1;
a[1].priority = 1;
a[2].pid=3;

a[2].at=3;
a[2].bt=2;
a[2].wt=-1;
a[2].tat=-1;
a[2].priority = 2;
a[3].pid=4;
a[3].at=3;
a[3].bt=1;
a[3].wt=-1;
a[3].tat=-1;
a[3].priority = 3;
a[4].pid=5;
a[4].at=4;
a[4].bt=6;
a[4].wt=-1;
a[4].tat=-1;
a[4].priority = 4;
a[5].pid=6;
a[5].at=6;
a[5].bt=3;
a[5].wt=-1;
a[5].tat=-1;
a[5].priority = 3;
int n=6,temp[7],t,count=0,max_p;
float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
for(int i=0;i<n;i++){
temp[i]=a[i].bt;
}
printf("|");
for(t=0;count!=n;t++){
max_p=0;
for(int i=0;i<n;i++){
if(((a[max_p].priority>a[i].priority)||(a[max_p].bt==0) )&& a[i].at<=t &&

a[i].bt>0 ){

max_p=i;
}
}

t+=a[max_p].bt-1;
a[max_p].bt=0;
printf("P%d|",a[max_p].pid);
count++;
a[max_p].wt=t+1-a[max_p].at-temp[max_p];
a[max_p].tat=t+1-a[max_p].at;
printf("(t=%d)|",t+1);

}

for(int i=0;i<6;i++){
total_WT+=a[i].wt;
total_TAT+=a[i].tat;
}
Avg_WT=total_WT/n;
Avg_TAT=total_TAT/n;
printf("\nID WT TAT\n");
for(int i=0;i<n;i++){
printf("%d %d\t%d\n",i+1,a[i].wt,a[i].tat);
}
printf("Average waiting time: %f",Avg_WT);
printf("Average waiting time: %f",Avg_TAT);
return 0;
}
