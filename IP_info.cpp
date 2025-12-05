#include  <string>
#include <iostream>
#include "stdc++.h"

using namespace std;
void IP_info() {
    string ip;
    cout << "Enter ip: ";
    cin >> ip;

    string cmd = "curl -s http://ip-api.com/json/" + ip + "?lang=ru";
    FILE *fp = popen(cmd.c_str(), "r");
    if (!fp) {
        cout << "Failed to execute command";
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        cout << buffer;
    }
    pclose(fp);
    cout << "\n";
}