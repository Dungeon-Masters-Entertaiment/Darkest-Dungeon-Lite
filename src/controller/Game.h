
#ifndef DARKEST_DUNGEON_LITE_GAME_H
#define DARKEST_DUNGEON_LITE_GAME_H
#include <memory>
#include "../model/Drawable/Map.h"
#include "../model/Creature/Squad.h"
#include <string>
#include <sstream>
//#include "view/graphics.h"

class Map;

class Monitor;
class Game { //singleton pattern
    inline static std::shared_ptr<Game> _instance = nullptr;

    std::unique_ptr<Map> _map;
    std::shared_ptr<Squad> _squad;
public:
    Game() = default;
    static std::shared_ptr<Game> getInstance();
    void Start();
    void ParseHeroes();
    std::shared_ptr<Squad> GetSquad(){
        return _squad;
    };
    void End();
    void Pause();
    void Resume();
    void Save();
    void Load();
    void Restart();
    void Exit();
    void ShowMenu();
    void ShowHelp();
    void ShowCredits();
    void ShowSettings();
    void ShowInventory();
    void ShowMap();
    void ShowSkills();
    void ShowQuests();
    void ShowStats();
    void ShowAchievements();
    void ShowLeaderboard();
    void ShowShop();
    void ShowDialog();
    void ShowBattle();
    void ShowDungeon();
    void ShowBoss();
    void ShowWin();
    void ShowLose();
    void ShowSave();
    void ShowLoad();
    void ShowRestart();
    void ShowExit();
    void ShowPause();
    void ShowResume();
    void ShowStart();
    void ShowEnd();
    void ShowError();
    void ShowWarning();
    void ShowInfo();
    void ShowMessage();
    void ShowNotification();
    void ShowConfirmation();
    void ShowQuestion();
    void ShowAnswer();
    void ShowInput();
    void ShowOutput();
};


#endif //DARKEST_DUNGEON_LITE_GAME_H
