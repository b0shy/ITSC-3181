/*
 * Sum of a*X[N]
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/timeb.h>

/* read timer in second */
double read_timer() {
    struct timeb tm;
    ftime(&tm);
    return (double) tm.time + (double) tm.millitm / 1000.0;
}

/* read timer in ms */
double read_timer_ms() {
    struct timeb tm;
    ftime(&tm);
    return (double) tm.time * 1000.0 + (double) tm.millitm;
}

#define REAL float
#define VECTOR_LENGTH 102400

/* initialize a vector with random floating point numbers */
void init(REAL A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        A[i] = (double) drand48();
    }
}

REAL sum(int N, REAL X[], REAL a) {
    int i;
    REAL result = 0.0;
    for (i = 0; i < N; ++i)
        result += a * X[i];
    return result;
}

int main(int argc, char *argv[]) {
    int N = VECTOR_LENGTH;
    int flg = 1;
    double elapsed; /* for timing */
    if (argc < 2) fprintf(stderr, "=======================\nUsage: sum [opts]\n -s <n>\t: problem size\n -b\t: baseline mode\n=======================\nsum -s %d\n", N);
    /* keep tracking options */
    if (argc > 1) {
        int i = 1;
        while (i < argc) {
            if(strcmp(argv[i], "-s") == 0) {          // -s: indicating problem size
                N = atoi(argv[i+1]);
                i += 2;
            } else if (strcmp(argv[i], "-b") == 0) {  // -b: indicating baseline mode
                flg = 0;
                i++;
            }
        }
    }
    
    REAL *X = (REAL*)malloc(sizeof(REAL)*N);
    REAL *Y = (REAL*)malloc(sizeof(REAL)*N);

    srand48((1 << 12));
    init(X, N);
    init(Y, N);
    REAL a = 0.1234;
    /* flag controlling execution of baseline with/without example run */
    if (flg == 0) {
        fprintf(stderr, "Now you are running baseline for number %d\n", N);
        return 0;
    }
    /* example run */
    elapsed = read_timer();
    REAL result = sum(N, X, a);
    elapsed = (read_timer() - elapsed);
    printf("======================================================================================================\n");
    printf("\tSum %d numbers\n", N);
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Performance:\t\tRuntime (ms)\t MFLOPS \n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Sum:\t\t\t%4f\t%4f\n", elapsed * 1.0e3, 2*N / (1.0e6 * elapsed));
    return 0;
}