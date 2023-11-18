#ifndef FIRSTLEVELSCENE_H
#define FIRSTLEVELSCENE_H

#include "player.h"
#include "enemy.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

class FirstLevelScene: public QObject
{
public:
    FirstLevelScene();
    ~FirstLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movePlayer();
    void noMovePlayer();
    void modifyPositionDir(int pos);
    int getXPlayerPos();
    int getYPlayerPos();
    void clearScene();
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    Player *p;
    QTimer *enemyTimer;
    std::vector<std::string> playerSprites = {":/spritres/characters/Rick.png", ":/spritres/enemies/Dragonfly.png"};
private slots:
    void generateEnemy();
};

#endif // FIRSTLEVELSCENE_H
