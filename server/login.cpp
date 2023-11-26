#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
using str = std::string;
#if _WIN32
    str os = "nt";
#else
    str os = "posix";
#endif

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    // Initialize the random seed based on the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int register_user(const str &name, const str &pass) {
    std::ifstream userstxt;
    if (os == "nt") {
        userstxt.open("..\\users\\users.txt");
    } else {
        userstxt.open("../users/users.txt");
    }
    int users = 0;
    str tempusers;
    if (userstxt.is_open()) {
        std::getline(userstxt, tempusers);
    }
    userstxt.close();
    users = std::stoi(tempusers);

    if (os == "nt") {
        str usernum = std::to_string((users + 1));
        std::system(("type nul > ..\\users\\user" + usernum + ".fusion").c_str());
        std::ofstream file(("..\\users\\user" + usernum + ".fusion"));
        if (file.is_open()) {
            file << "username=" << name << '\n';
            file << "password=" << pass << '\n';
        }
    } else {
        str usernum = std::to_string((users + 1));
        std::system(("touch ../users/user" + usernum + ".fusion").c_str());
        std::ofstream file(("../users/user" + usernum + ".fusion"));
        if (file.is_open()) {
            file << "username=" << name << '\n';
            file << "password=" << pass << '\n';
        }
    }
    return (users + 1); // Hello {USERNAME}! You're the {USERS+1} user!
}

long long int login(const str &user, const str &pass, const int &usernumber) {
    str path;
    if (os == "nt") {
        path = "users\\";
    } else {
        path = "users/";
    }
    std::hash<str> userhash;
    int userhashv = userhash(user);
    std::hash<str> passhash;
    int passhashv = passhash(pass);

    int sum = userhashv + passhashv;
    long long int sessionid = sum * (getRandomNumber(200, 5000));
    return sessionid;
}
