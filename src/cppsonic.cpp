#include <iostream>
#include "cppsonic.h"
#include "cpr/cpr.h"

CppSonic::CppSonic()= default;


int CppSonic::auth(const std::string& address, const std::string& username, const std::string& token) {
    addr = address;
    u = username;
    t = token;
    auto r = cpr::Get(cpr::Url{addr + "rest/ping.view"},
                      cpr::Parameters{{"u", u}, {"p", t}, {"v", "1.16.0"}, {"c", "cppsonic"}});
    std::cout << r.url << std::endl << r.text << std::endl;
    return 0;
}
