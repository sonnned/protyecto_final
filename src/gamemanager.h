#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "macros.h"
#include "menuscene.h"
#include "firstlevelscene.h"
#include "secondlevelscene.h"
#include "player.h"

#include <iostream>
#include <vector>
#include <string>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>
#include <QBrush>
#include "ui_game.h"

class Game;

class GameManager
{
public:
    GameManager(QGraphicsView *g);
    ~GameManager();
    void showLevelScene(int currentLevelScene);
    void showMenu();
    void playerMovement(int pos);
    void NaveMovement(char key);
    void playerNoMovement();
    void invokeBullet(int x, int y);
    void clearCurrentScene();
private:
    int currentLevelScene = 0; // 0 -> NADA // 1 -> PRIMER NIVEL // 2 -> SEGUNDO NIVEL
    QGraphicsView *g;
    FirstLevelScene *fLevel;
    SecondLevelScene *sLevel;
    MenuScene *mScene;
};

#endif // GAMEMANAGER_H
