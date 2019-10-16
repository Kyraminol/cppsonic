#ifndef CPPSONIC_H
#define CPPSONIC_H

#include <string>
#include "cpr/cpr.h"

class CppSonic {
    public:
         CppSonic();
         int auth(const std::string& address, const std::string& username, const std::string& token);
    private:
        std::string addr;
        std::string u;
        std::string t;
        cpr::Parameters parameters = cpr::Parameters{{"v", "1.16.0"}, {"c", "cppsonic"}};

        const std::string ping = "rest/ping.view";
};

#endif //CPPSONIC_H
