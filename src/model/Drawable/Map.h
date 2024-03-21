#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include <iostream>

#include "Drawable.h"
#include "model/MapGenerators/MapFabric.h"
// #include "model/Rooms/Cell.h"
#include "model/Rooms/Hall.h"
// #include "model/Rooms/Room.h"

#include "nlohmann/json.hpp"
typedef nlohmann::json json;
class Hall;
class Room;

class Map : public AbstractDrawable {
public:
  std::vector<std::vector<char>> _body;
  std::vector<std::shared_ptr<Room>> _rooms;
  std::vector<std::shared_ptr<Hall>> _halls;
  std::shared_ptr<Room> _starting_position = nullptr;

  friend class AntohaFabric;
  friend class BinarySpaceMapGenerator;
  friend class Game;

public:
  Map() = default;
  Map(int width, int height) {
    _body.assign(width, std::vector<char>(height));
  }


  Map &operator=(const Map &) = delete;

  void Draw(std::shared_ptr<window_work>, FSMGame &) override;
  friend void to_json(json &j, const Map &map);
  friend void from_json(const json &j, Map &map);
};

#endif // DARKEST_DUNGEON_LITE_MAP_H