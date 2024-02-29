
#ifndef DARKEST_DUNGEON_LITE_GAME_H
#define DARKEST_DUNGEON_LITE_GAME_H


class Game { //singleton pattern
    static Game* _instance;
public:
    Game();
    void Start();
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
