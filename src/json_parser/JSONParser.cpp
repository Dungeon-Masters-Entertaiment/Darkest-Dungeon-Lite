#include "JSONParser.h"


std::map<std::string, nlohmann::json> JSONParser::parseJSON(const std::string &jsonString) {
  nlohmann::json j = nlohmann::json::parse(jsonString);
  return j.get<std::map<std::string, nlohmann::json> >();
}

std::string JSONParser::toJson(const std::map<std::string, nlohmann::json> &jsonMap) {
  nlohmann::json json(jsonMap);
  return json.dump();
}

template<class T>
std::string JSONParser::objectToJson(const T &obj) {
  nlohmann::json json = obj;
  return json.dump();
}

template<typename  T>
T JSONParser::jsonToObject(const std::string &jsonString) {
  nlohmann::json json = nlohmann::json::parse(jsonString);
  return json.get<T>();
}
