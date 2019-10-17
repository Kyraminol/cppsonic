#ifndef CPPSONIC_H
#define CPPSONIC_H

#include <string>
#include "cpr/cpr.h"
#include "tinyxml2/tinyxml2.h"

class CppSonic {
    public:
         CppSonic();
         int auth(const std::string& address, const std::string& username, const std::string& token);
         const std::string api_version = "1.16.1";
    private:
        std::string addr;
        std::string u;
        std::string t;
        cpr::Parameters parameters = cpr::Parameters{{"v", api_version}, {"c", "cppsonic"}};

        const std::string main_path = "rest/";
        const std::string ping_path = main_path + "ping";
        const std::string indexes_path = main_path + "getIndexes";

        int request(const std::string& path, const cpr::Parameters& params, tinyxml2::XMLDocument &doc);
};

#endif //CPPSONIC_H
