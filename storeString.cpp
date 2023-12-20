#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> database;

    // Reading the first block of information
    std::string key;
    while (std::cin >> key && key != "*") {
        database.insert(key);
    }

    // Reading the second block of actions
    std::string cmd, k;
    while (std::cin >> cmd >> k && cmd != "***") {
        if (cmd == "find") {
            if (database.find(k) != database.end()) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        } else if (cmd == "insert") {
            auto result = database.insert(k);
            if (result.second) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        }
    }

    return 0;
}