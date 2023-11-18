#ifndef ENEMY_H
#define ENEMY_H

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

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int health, int attack, int defense, int speed, int limitOfSprites, std::string characterSprites, int timerInterval);
    ~Enemy();
    void setIsMoving(bool newIsMoving);
private:
    int health;
    int attack;
    int defense;
    int speed;
    int targetX = 0;
    int targetY = 0;
    bool is_moving = true;
    int currentSpriteRows = 0;
    int limitOfSprites;
    int timerInterval;
    std::string characterSprites;
    QTimer *timer;
    QPixmap *sprite;
    void cutSprite();
    void followPlayer(int playerX, int playerY);
private slots:
    void changeSprite();
public slots:
    void changePosition(int x, int y);
};

#endif // ENEMY_H
