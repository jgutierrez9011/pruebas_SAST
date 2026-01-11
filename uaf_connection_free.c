#include <stdio.h>
#include <stdlib.h>

typedef void* bar;
bar foo;

bar connection() {
    foo = malloc(1024);
    return foo;
}

void endConnection(bar fooParam) {
    free(fooParam);
}

int main() {
    while (1) { // thread 1
        // On a connection
        foo = connection(); // thread 2

        // When the connection ends
        endConnection(foo);

        // (sin break a propósito)
    }
    return 0;
}
