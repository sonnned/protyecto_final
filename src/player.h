#ifndef PLAYER_H
#define PLAYER_H

#include "macros.h"

#include <iostream>
#include <vector>
#include <string>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTransform>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(int health, int attack, int defense, int speed, int limitOfSprites, std::string characterSprites, int timerInterval);
    ~Player();
    int getHealth();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getXPos();
    int getYPos();
    void modifyPositionVector(int pos);
    void setIsMoving(bool newIsMoving);
    void movePlayer();
private:
    int health;
    int attack;
    int defense;
    int speed;
    bool is_moving = false;
    int currentSpriteRows = 0;
    int currentSpriteCols = 0;
    //UP, DOWN , LEFT, RIGHT
    std::vector<int> movementPosition = {0, 1, 0, 0};
    int limitOfSprites;
    int timerInterval;
    std::string characterSprites;
    QTimer *timer;
    QPixmap *sprite;
    void cutSprite();
private slots:
    void changeSprite();
};

#endif // PLAYER_H
