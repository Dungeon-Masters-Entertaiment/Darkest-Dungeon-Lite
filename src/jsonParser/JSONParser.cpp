#include "JSONParser.h"

std::map<std::string, nlohmann::json> JSONParser::parseJSON(const std::string &jsonString) {
    nlohmann::json j = nlohmann::json::parse(jsonString);
    return j.get<std::map<std::string, nlohmann::json> >();
}

std::string JSONParser::toJson(const std::map<std::string, nlohmann::json> &jsonMap) {
    nlohmann::json j(jsonMap);
    return j.dump();
}


