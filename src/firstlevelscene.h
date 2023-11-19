#ifndef FIRSTLEVELSCENE_H
#define FIRSTLEVELSCENE_H

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "playerscore.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>

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
    void generateBullet(int x, int y);
    void startLevel();
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    Player *p;
    QTimer *enemyTimer;
    PlayerScore *pScoreEnemies;
    PlayerScore *pScoreLife;
    int currentEnemyID = 1;
    int amountOfEnemies = 0;
    int deadEnemies = 0;
    std::vector<std::string> playerSprites = {":/spritres/characters/Rick.png", ":/spritres/enemies/Dragonfly.png", ":/spritres/enemies/car/Projectile.png"};
private slots:
    void generateEnemy();
    void amountOfEnemiesDecrement();
};

#endif // FIRSTLEVELSCENE_H
