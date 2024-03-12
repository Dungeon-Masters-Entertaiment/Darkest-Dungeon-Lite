//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_TREASUREHALLWAY_H
#define DARKEST_DUNGEON_LITE_TREASUREHALLWAY_H


class TreasureHallway : public TreasureCell{
    public:
        TreasureHallway(int id) {
            cell = TreasureCell(id);
            cell.dificulty = "Low";
            return cell;
        }
};


#endif //DARKEST_DUNGEON_LITE_TREASUREHALLWAY_H
