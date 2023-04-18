#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int i, sum = 0;
    float avg;
    int arr[SIZE];

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    for (i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    avg = (float) sum / SIZE;

    printf("Average: %.2f\n", avg);
    return 0;
}
