#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_SIZE 100
void bubbleSort(int array[], int size) {
int i, j;
for (i = 0; i < size - 1; i++) {
for (j = 0; j < size - i - 1; j++) {
if (array[j] > array[j + 1]) {
int temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
}
}
}
}
int main() {
sleep(5);
key_t key = 1010;
int shmid = shmget(key, sizeof(int) * MAX_SIZE, 0666);

if (shmid == -1) {
perror("shmget");
exit(1);
}
int* sharedArray = (int*)shmat(shmid, NULL, 0);
if (sharedArray == (int*)-1) {
perror("shmat");
exit(1);
}
int count = 0;
while (sharedArray[count] != '\0' && count < MAX_SIZE) {
count++;
}
bubbleSort(sharedArray, count);
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
shmctl(shmid, IPC_RMID, NULL); // Delete the shared memory segment
return 0;
}
