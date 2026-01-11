#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randNum = rand();
    printf("rand: %d\n", randNum);
    return 0;
}
