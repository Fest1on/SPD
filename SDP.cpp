#include <iostream>
#include <string>
#include "termcolor.hpp"

void start_dos();

void wifi_scaner();

using namespace std;
int main() {
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
            exit(0);
    }
}







    

