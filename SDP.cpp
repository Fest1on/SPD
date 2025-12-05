#include <iostream>
#include <string>
#include "termcolor.hpp"

void start_dos();
void wifi_scaner();
void IP_info();
void lt();

using namespace std;
int main(int argc,char**argv) {
    if(!getenv("TOR")) {
        system("tor --SocksPort 9050 --quiet & sleep 4");
        setenv("TOR","1",1);
        char p[1024]={};
        readlink("/proc/self/exe",p,sizeof(p));
        execve(p,argv,environ);
    }
    system("clear");
    string logo =
           "  /$$$$$$  /$$$$$$$  /$$$$$$$\n"
           " /$$__  $$| $$__  $$| $$__  $$\n"
           "| $$  \\__/| $$  \\ $$| $$  \\ $$\n"
           "|  $$$$$$ | $$  | $$| $$$$$$$/\n"
           " \\____  $$| $$  | $$| $$____/\n"
           " /$$  \\ $$| $$  | $$| $$\n"
           "|  $$$$$$/| $$$$$$$/| $$\n"
           " \\______/ |_______/ |__/\n"
           "\n";
    cout << termcolor::red << logo << termcolor::reset;
    cout << "Welcome to SDP\n\n";
    cout << "1.Wifi scaner\n";
    cout << "2.DOS\n";
    cout << "3.IP info\n";
    cout << "3.Exit\n";
    cout << "\n";
    cout << "Enter your choice: ";
    int n;
    cin >> n;
    switch (n) {
        case 1:
            wifi_scaner();
            break;
        case 2:
            start_dos();
            break;
        case 3:
            IP_info();
            break;
        case 4:
            exit(0);
            break;
    }
}







    

