#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "menuscene.h"
#include "firstlevelscene.h"
#include "secondlevelscene.h"
#include "player.h"

#include <iostream>
#include <vector>
#include <string>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>
#include <QBrush>
#include "ui_game.h"

class Game;

class GameManager
{
public:
    GameManager(Game *g, Ui::Game *ui);
    ~GameManager();
    void changeCurrentScene(int currentView);
    void movePlayer(int newX, int newY);
    bool checkIsPlayerOnScreen(int x, int y);
    void changePlayerPosition(int pos);
    void changeMovement();
private:
    Game *g;
    Ui::Game *ui;
    QGraphicsScene *s;
    MenuScene *mScene;
    FirstLevelScene *fScene;
    SecondLevelScene *sScene;
    Player *player;
    int currentPage = 0;
    std::vector<std::string> playerSprites = {":/spritres/characters/Rick.png", ":/spritres/characters/Morty.png"};
    QPixmap *background_2;
    QBrush *brocha;
};

#endif // GAMEMANAGER_H
