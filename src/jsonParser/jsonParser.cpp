#include "jsonParser.h"

std::map<std::string, nlohmann::json> jsonParser::parseJSON(const std::string& jsonString) {
  nlohmann::json json = nlohmann::json::parse(jsonString);
  return json.get<std::map<std::string, nlohmann::json>>();
}

std::string jsonParser::toJson(const std::map<std::string, nlohmann::json>& jsonMap) {
  nlohmann::json json(jsonMap);
  return json.dump();
}

template <typename T>
std::string jsonParser::objectToJson(const T& obj) {
  nlohmann::json json = obj;
  return json.dump();
}

template <typename T>
T jsonParser::jsonToObject(const std::string& jsonString) {
  nlohmann::json json = nlohmann::json::parse(jsonString);
  return json.get<T>();
}
