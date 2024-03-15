//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_BATTLEHALLWAY_H
#define DARKEST_DUNGEON_LITE_BATTLEHALLWAY_H


class BattleHallway: public BattleCell {
    public:
        BattleHallway(int id) {
            Cell cell = BattleCell(id);
            cell.dificulty = "Low";
            return cell;
        }
};


#endif //DARKEST_DUNGEON_LITE_BATTLEHALLWAY_H
