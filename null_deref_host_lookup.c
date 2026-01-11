#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

void validate_addr_form(char *user_supplied_addr) {
    // routine that ensures user_supplied_addr is in the right format for conversion
    // (vacío a propósito)
}

void host_lookup(char *user_supplied_addr) {
    struct hostent *hp;
    in_addr_t addr;
    char hostname[64];

    validate_addr_form(user_supplied_addr);
    addr = inet_addr(user_supplied_addr);

    hp = gethostbyaddr(&addr, sizeof(struct in_addr), AF_INET);
    strcpy(hostname, hp->h_name);
    printf("%s\n", hostname);
}

int main() {
    host_lookup("256.256.256.256");
    return 0;
}
