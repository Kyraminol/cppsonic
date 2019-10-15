#include <iostream>
#include "src/cppsonic.h"

int main() {
    CppSonic cppsonic;
    std::string address;
    std::string username;
    std::string token;
    int auth_result = cppsonic.auth(address, username, token);
    std::cout << "Auth_result: " << auth_result;
    return 0;
}
