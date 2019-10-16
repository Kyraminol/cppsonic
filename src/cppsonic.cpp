#include <iostream>
#include "cppsonic.h"
#include "cpr/cpr.h"
#include "tinyxml2/tinyxml2.h"

CppSonic::CppSonic() = default;


int CppSonic::auth(const std::string& address, const std::string& username, const std::string& token) {
    addr = address;
    u = username;
    t = token;
    parameters.AddParameter({"u", u});
    parameters.AddParameter({"p", t});
    cpr::Response r = cpr::Get(cpr::Url{addr + ping_path}, parameters);
    tinyxml2::XMLDocument doc;
    doc.Parse(r.text.c_str());
    tinyxml2::XMLNode *rootnode = doc.FirstChild();
    tinyxml2::XMLElement *firstelement = rootnode->NextSiblingElement();
    std::string first_element_name = firstelement->Attribute("status");
    std::cout << r.url << std::endl;
    std::cout << first_element_name << std::endl;
    return 0;
}
