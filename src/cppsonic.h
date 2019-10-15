#ifndef CPPSONIC_H
#define CPPSONIC_H

#include <string>

class CppSonic {
    public:
         CppSonic();
         int auth(const std::string& address, const std::string& username, const std::string& token);
    private:
        std::string addr;
        std::string u;
        std::string t;
};

#endif //CPPSONIC_H
