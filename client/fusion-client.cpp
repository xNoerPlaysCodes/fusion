// C++23
// Linux and macOS Client
// Fusion 0.10.0

#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "server/command_handler.cpp"
#include "server/message_handler.cpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
namespace fs = std::filesystem;
using str = std::string;
str instructions_string = R"(Instructions to launch Fusion-Chat Client on your device..

1. Open the terminal
2. Go to where client executable is installed
3. Type:
    ./fusion-client --terminal
4. Enjoy
To get instructions again, type:
    ./fusion-client --instructions
(Make sure to close this window first)
)";

void drawWindow() {
    bool loadingTextVisible = true;
    bool exitMessageVisible = false; // Add a flag to control the exit message
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fusion Chat Client Instructions");
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSerif-Regular.ttf")) {
        exit(1);
    }
    sf::Text instructions(instructions_string, font, 15);
    instructions.setFillColor(sf::Color::Black);
    instructions.setPosition(10.0f, 10.0f);

    // Clock

    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(instructions);
        window.display();
    }
}

void client() {
    /**@assuming
     * The server files are in server/<br>
     * The users files are in users/<br>
     * <br>
     * We can create a client instance dependent on those things...
     */
    std::cout << "Welcome to Fusion Chat!\n";
    std::cout << "Connecting to: FUSION.LOCALHOST_SERVER\n";
    std::cout << YELLOW << "Attempting connection...\n" << RESET;
    auto condition = ( (fs::exists("./server/") && fs::exists("./users/")) );
    if (!condition) {
        std::cout << RED << "Connection Failed.\n" << RESET;
        return;
    }
    std::cout << GREEN << "Connection Successful.\n" << RESET;
    std::cout << "Enter your username: ";
    str username;
    std::getline(std::cin, username);
    std::cout << "You'll be known as " << username << " for this session" << '\n';
    std::cout << "Type a message and press enter to chat.\nTo quit, press .q\n";
    bool ch_running = true;
    while (ch_running) {
        std::cout << "> ";
        str ui;
        std::getline(std::cin, ui);
        if (ui == ".q") {
            str code = command_handler(".q");
            if (code == "CH_RUNNING_FALSE") {
                ch_running = false;
            } else if (code == "CONTINUE") {
                continue;
            } else if (code == "UNKNOWN_COMMAND"){
                std::cout << "error: invalid choice\n";
            }
        } else {
            message_handler(ui, username);
        }
    }
}

int main(int argc, char **argv) {
    str argvstr[argc];
    for (int i = 0; i < argc; i++) {
        argvstr[i] = argv[i];
    }

    if (argc != 2) {
        drawWindow();
    } else {
        if (argvstr[1] == "--terminal") {
            client();
        } else if (argvstr[1] == "--instructions") {
            drawWindow();
        } else {
            std::cout << "error: invalid arguments\n";
        }
    }
    return 0;
}
