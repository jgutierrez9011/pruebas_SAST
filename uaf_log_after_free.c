#include <stdio.h>
#include <stdlib.h>

#define SIZE 64

void logError(const char *msg, const char *ptr) {
    /* Vulnerable: uses ptr that may be freed */
    printf("%s: %s\n", msg, ptr);
}

int main() {
    int err = 1;
    int abrt = 0;

    char *ptr = (char *)malloc(SIZE);
    if (!ptr) return 1;

    snprintf(ptr, SIZE, "temporary buffer");

    if (err) {
        abrt = 1;
        free(ptr);
    }

    if (abrt) {
        logError("operation aborted before commit", ptr);
    }

    return 0;
}
