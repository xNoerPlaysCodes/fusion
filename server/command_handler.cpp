#include <iostream>
using str = std::string;
str command_handler(const str &command) {
    if (command == ".q") {
        char confirm;
        std::cout << "Are you sure you want to quit? ";
        std::cin >> confirm;
        if (confirm == 'y') {
            return "CH_RUNNING_FALSE";
        } else {
            return "CONTINUE";
        }
    } else {
        return "UNKNOWN_COMMAND";
    }
}
