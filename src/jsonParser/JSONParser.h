#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <iostream>
#include <map>
#include <nlohmann/json.hpp>

class JSONParser {
public:
  static std::map<std::string, nlohmann::json>
  parseJSON(const std::string &jsonString);

  static std::string
  toJson(const std::map<std::string, nlohmann::json> &jsonMap);

  template <typename T> static std::string objectToJson(const T &obj) {
    nlohmann::json j = obj;
    return j.dump();
  }

  template <typename T> static T jsonToObject(const std::string &jsonString) {
    nlohmann::json j = nlohmann::json::parse(jsonString);
    return j.get<T>();
  }
};

#endif // JSONPARSER_H
