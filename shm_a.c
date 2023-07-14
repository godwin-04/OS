#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_SIZE 100
int main() {
key_t key = 1010;
int shmid = shmget(key, sizeof(int) * MAX_SIZE, IPC_CREAT | 0666);
if (shmid == -1) {
perror("shmget");
exit(1);
}
int* sharedArray = (int*)shmat(shmid, NULL, 0);
if (sharedArray == (int*)-1) {
perror("shmat");
exit(1);
}
FILE* file = fopen("inpfile", "r");
if (file == NULL) {
perror("fopen");
exit(1);
}
int num;
int count = 0;
while (fscanf(file, "%d", &num) != EOF && count < MAX_SIZE) {

sharedArray[count] = num;
count++;
}
fclose(file);
shmdt(sharedArray);
return 0;
}
