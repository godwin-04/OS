#include <stdio.h>
#include
<pthread.h>
#define NUM_READERS 5
#define NUM_WRITERS 2
pthread_mutex_t mutex;
pthread_cond_t cond_readers, cond_writers;
int readers_count = 0;
int resource = 0;
void* reader(void* arg)
{
int reader_id = *(int*)arg;
pthread_mutex_lock(&mutex);

while (readers_count == -1) {
pthread_cond_wait(&cond_readers, &mutex);
}

readers_count++;
pthread_mutex_unlock(&mutex);
// Reading
printf("Reader %d is reading resource: %d\n", reader_id, resource);
pthread_mutex_lock(&mutex);
readers_count--;

if (readers_count == 0) {
pthread_cond_signal(&cond_writers);
}
pthread_mutex_unlock(&mutex);
pthread_exit(NULL);
}
void* writer(void* arg)
{
int writer_id = *(int*)arg;
pthread_mutex_lock(&mutex);
while (readers_count != 0) {
pthread_cond_wait(&cond_writers, &mutex);
}
readers_count = -1;
pthread_mutex_unlock(&mutex);

// Writing
resource++;
printf("Writer %d is writing resource: %d\n", writer_id, resource);
pthread_mutex_lock(&mutex);
readers_count = 0;
pthread_cond_broadcast(&cond_readers);
pthread_mutex_unlock(&mutex);
pthread_exit(NULL);
}
int main()
{
pthread_t readers[NUM_READERS];
pthread_t writers[NUM_WRITERS];
pthread_mutex_init(&mutex, NULL);
pthread_cond_init(&cond_readers, NULL);
pthread_cond_init(&cond_writers, NULL);
int reader_ids[NUM_READERS];
int writer_ids[NUM_WRITERS];
// Create reader threads
for (int i = 0; i < NUM_READERS; i++) {
reader_ids[i] = i + 1;
pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
}
// Create writer threads
for (int i = 0; i < NUM_WRITERS; i++) {
writer_ids[i] = i + 1;
pthread_create(&writers[i], NULL, writer, &writer_ids[i]);

}
// Join reader threads
for (int i = 0; i < NUM_READERS; i++) {
pthread_join(readers[i], NULL);
}

// Join writer threads
for (int i = 0; i < NUM_WRITERS; i++) {
pthread_join(writers[i], NULL);
}
pthread_mutex_destroy(&mutex);
pthread_cond_destroy(&cond_readers);
pthread_cond_destroy(&cond_writers);
return 0;
}
