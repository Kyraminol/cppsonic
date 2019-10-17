#include <iostream>
#include "cppsonic.h"
#include "cpr/cpr.h"
#include "tinyxml2/tinyxml2.h"

CppSonic::CppSonic() = default;


int CppSonic::auth(const std::string& address, const std::string& username, const std::string& token) {
    // Assign to class global variables
    addr = address;
    u = username;
    t = token;
    // Try credentials with ping
    tinyxml2::XMLDocument doc;
    int result = request(ping_path, parameters, doc);
    return result;
}

int CppSonic::request(const std::string& request_path, const cpr::Parameters& request_parameters, tinyxml2::XMLDocument& doc){
    cpr::Parameters p = request_parameters;
    p.AddParameter({"u", u});
    p.AddParameter({"p", t});
    cpr::Response r = cpr::Get(cpr::Url{addr + request_path}, p);
    doc.Parse(r.text.c_str());
    tinyxml2::XMLElement *first_element = doc.FirstChildElement();
    if(first_element == nullptr) return -1;
    std::string status = first_element->Attribute("status");
    if(status == "ok")
        return 0;
    else{
        tinyxml2::XMLElement *error = first_element->FirstChildElement("error");
        return std::stoi(error->Attribute("code"));
    };
}


