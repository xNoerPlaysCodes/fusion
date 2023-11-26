#include <iostream>
#include <fstream>
using str = std::string;

void message_handler(const str &message, const str &user) {
    std::ofstream messages_output("messages.txt", std::ios::app);
    std::ifstream mo_read("messages.txt");
    if (messages_output.is_open()) {
        messages_output << message << '\n';
    }
    messages_output.close();
    mo_read.close();
}
