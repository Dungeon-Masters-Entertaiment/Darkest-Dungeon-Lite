//
// Created by andru on 12.03.2024.
//

#include "Cell.h"
#include "nlohmann/json.hpp"
void to_json(nlohmann::json &j, const Cell &cell) {
  j["chr"] = cell.chr;
  j["view"] = cell.view;
  j["id"] = cell.id;
  j["name"] = cell.name;
  j["description"] = cell.description;
  j["enemy_presence"] = cell.enemy_presence;
  j["difficulty"] = cell.difficulty;
  j["special_features"] = cell.special_features;
  j["x"] = cell.x;
  j["y"] = cell.y;
  j["width"] = cell.width;
  j["height"] = cell.height;
}
void from_json(const nlohmann::json &j, Cell &cell) {
  cell.chr = j.at("chr").get<char>();
  cell.view = j.at("view").get<int>();
  cell.id = j.at("id").get<int>();
  cell.name = j.at("name").get<std::string>();
  cell.description = j.at("description").get<std::string>();
  cell.enemy_presence = j.at("enemy_presence").get<bool>();
  cell.difficulty = j.at("difficulty").get<std::string>();
  cell.special_features = j.at("special_features").get<std::vector<std::string>>();
  cell.x = j.at("x").get<int>();
  cell.y = j.at("y").get<int>();
  cell.width = j.at("width").get<int>();
  cell.height = j.at("height").get<int>();
}