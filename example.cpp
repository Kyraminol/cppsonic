#include <iostream>
#include "src/cppsonic.h"

int main() {
    CppSonic cppsonic;
    std::string address;
    std::string username;
    std::string token;
    cppsonic.set_debug(true);
    int auth_result = cppsonic.init(address, username, token);
    std::cout << "Auth_result: " << auth_result;
    return 0;
}
