#include <map>
#include <nlohmann/json.hpp>

#ifndef JSONPARSER_H
#define JSONPARSER_H

class JSONParser {
  public:
    std::map<std::string, nlohmann::json> parseJSON(const std::string &jsonString);

    std::string toJson(const std::map<std::string, nlohmann::json> &jsonMap);

    template<typename T>
    std::string objectToJson(const T &obj);

    template<typename T>
    T jsonToObject(const std::string &jsonString);
};


#endif // JSONPARSER_H
