#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "menuscene.h"
#include "firstlevelscene.h"
#include "secondlevelscene.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include "ui_game.h"

class Game;

class GameManager
{
public:
    GameManager(Game *g, Ui::Game *ui);
    ~GameManager();
    void changeCurrentScene(int currentView);
private:
    Game *g;
    Ui::Game *ui;
    QGraphicsScene *s;
    MenuScene *mScene;
    FirstLevelScene *fScene;
    SecondLevelScene *sScene;
    int currentPage = 0;
};

#endif // GAMEMANAGER_H
