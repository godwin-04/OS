#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 2

// Structure to hold the result
struct Result {
    int largestEven;
    int smallestOdd;
};

// Thread function to find the largest even number
void* findLargestEven(void* arg) {
    int* numbers = (int*)arg;
    int largestEven = -1;

    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 0 && numbers[i] > largestEven) {
            largestEven = numbers[i];
        }
    }

    return (void*)(long)largestEven;
}

// Thread function to find the smallest odd number
void* findSmallestOdd(void* arg) {
    int* numbers = (int*)arg;
    int smallestOdd = -1;

    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 != 0 && (smallestOdd == -1 || numbers[i] < smallestOdd)) {
            smallestOdd = numbers[i];
        }
    }

    return (void*)(long)smallestOdd;
}

int main() {
    int numbers[] = { 3, 5, 2, 10, 8, 1, 9, 6, 4, 7 };
    pthread_t threads[MAX_THREADS];
    struct Result results[MAX_THREADS];

    // Create the threads
    pthread_create(&threads[0], NULL, findLargestEven, (void*)numbers);
    pthread_create(&threads[1], NULL, findSmallestOdd, (void*)numbers);

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], (void**)&results[i]);
    }

    // Find the largest even number
    int largestEven = (int)(long)results[0].largestEven;
    for (int i = 1; i < MAX_THREADS; i++) {
        if (results[i].largestEven > largestEven) {
            largestEven = results[i].largestEven;
        }
    }

    // Find the smallest odd number
    int smallestOdd = (int)(long)results[0].smallestOdd;
    for (int i = 1; i < MAX_THREADS; i++) {
        if (results[i].smallestOdd < smallestOdd) {
            smallestOdd = results[i].smallestOdd;
        }
    }

    printf("Largest even number: %d\n", largestEven);
    printf("Smallest odd number: %d\n", smallestOdd);

    return 0;
}
