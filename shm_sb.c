#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_SIZE 100
int main() {
sleep(5);
key_t key = 1010;
int shmid = shmget(key, sizeof(int) * (MAX_SIZE + 1), 0666);
if (shmid == -1) {
perror("shmget");
exit(1);
}
int* sharedArray = (int*)shmat(shmid, NULL, 0);
if (sharedArray == (int*)-1) {
perror("shmat");
exit(1);
}
int done = 0;
while (!done) {
done = sharedArray[MAX_SIZE];
usleep(10000);
}
int count = 0;
while (sharedArray[count] != '\0' && count < MAX_SIZE) {
count++;
}
// Sort the array using selection sort
for (int i = 0; i < count - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < count; j++) {
if (sharedArray[j] < sharedArray[minIndex]) {

minIndex = j;
}
}
int temp = sharedArray[i];
sharedArray[i] = sharedArray[minIndex];
sharedArray[minIndex] = temp;
}
FILE* file = fopen("outfile", "w");
if (file == NULL) {
perror("fopen");
exit(1);
}
for (int i = 0; i < count; i++) {
fprintf(file, "%d ", sharedArray[i]);
}
fclose(file);
shmdt(sharedArray);
return 0;
}
