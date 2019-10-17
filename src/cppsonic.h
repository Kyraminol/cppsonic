#ifndef CPPSONIC_H
#define CPPSONIC_H

#include <string>
#include "cpr/cpr.h"
#include "tinyxml2/tinyxml2.h"

class CppSonic {
    public:
        CppSonic();
        int init(const std::string& address, const std::string& username, const std::string& password, const std::string& path="rest/");

        int ping();


        void set_debug(bool debug);

        const std::string api_version = "1.16.1";
    private:
        std::string base_address;
        std::string base_path = "rest/";
        std::string u;
        std::string p;
        cpr::Parameters base_parameters = cpr::Parameters{{"v", api_version}, {"c", "cppsonic"}};
        bool debug_mode = false;

        int request(const std::string& path, const cpr::Parameters& params, tinyxml2::XMLDocument &doc);

        void debug_print(const std::string& to_print);
};

#endif //CPPSONIC_H
