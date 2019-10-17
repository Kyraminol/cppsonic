#include <iostream>
#include "cppsonic.h"
#include "cpr/cpr.h"
#include "tinyxml2/tinyxml2.h"


// Public interface
CppSonic::CppSonic() = default;

int CppSonic::init(const std::string& address, const std::string& username, const std::string& password, const std::string& path, bool debug){
    // Assign to class global variables
    base_address = address;
    u = username;
    p = password;
    if(debug) debug_mode = debug;
    // Try credentials with ping
    int result = ping();
    return result;
}

int CppSonic::init(const std::string &address, const std::string &username, const std::string &password, bool debug) {
    return init(address, username, password, "rest/", debug);
}

int CppSonic::ping() {
    std::string endpoint = "ping";
    tinyxml2::XMLDocument doc;
    int result = request(endpoint, base_parameters, doc);
    return result;
}


// Private interface
int CppSonic::request(const std::string& endpoint, const cpr::Parameters& parameters, tinyxml2::XMLDocument& doc){
    cpr::Parameters request_parameters = parameters;
    request_parameters.AddParameter({"u", u});
    request_parameters.AddParameter({"p", p});
    cpr::Response r = cpr::Get(cpr::Url{base_address + base_path + endpoint}, request_parameters);
    debug_print(r.url);
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

void CppSonic::debug_print(const std::string &to_print) {
    if(debug_mode) std::cout << "[Debug] " << to_print << std::endl;
}
