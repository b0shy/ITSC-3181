#include <stdio.h>

int main() {
    int t0 = 60;
    int t1 = 0;

    while (t1 != t0) {
        t1 += 5;
        t0--;
    }

    if (t1 == 0) {
        printf("Success\n");
        return 42;
    } else {
        printf("Failure\n");
        return 0;
    }
}
