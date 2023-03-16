#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 100

int main(void) {
  int B[M];
  int B2[M];

  srand(time(NULL));

  for (int i = 0; i < M; i++) {
    B[i] = rand() % 100;
  }

  for (int i = 1; i < M - 1; i++) {
    B2[i] = (B[i - 1] + B[i] + B[i + 1]) / 3;
  }

  B2[0] = B[0];
  B2[M - 1] = B[M - 1];

  printf("B: ");
  for (int i = 0; i < M; i++) {
    printf("%d ", B[i]);
  }
  printf("\n");

  printf("B2:");
  for (int i = 0; i < M; i++) {
    printf("%d ", B2[i]);
  }
  printf("\n");

  return 0;
}