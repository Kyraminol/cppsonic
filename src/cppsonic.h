#ifndef CPPSONIC_H
#define CPPSONIC_H

#include <string>

class CppSonic {
    public:
        explicit CppSonic(const std::string& addr);
    private:
        std::string address;
};

#endif //CPPSONIC_H
