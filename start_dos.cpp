#include <iostream>
#include <string>
#include <cstdlib>
#include "CLI11.hpp"

void lt();

using namespace std;
void start_dos() {

    cout << "Please enter ip";
    string ip;
    cin >> ip;
    cout << "Enter a cycle of ping";
    int cycle;
    cin >> cycle;
    for (int i = 0; i < cycle; i++) {
        lt();
        system(("ping " + ip).c_str());
    }
}