#include <stdio.h>
#include <stddef.h>

int main() {
    int a = 5, b = 6;
    size_t len = a - b;
    char buf[len]; // Just blows up the stack (VLA gigante)
    buf[0] = 'A';
    printf("len=%zu\n", len);
    return 0;
}
