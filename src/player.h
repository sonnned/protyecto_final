#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(int health, int attack, int defense, int speed, int x, int y, int limitOfSprites, std::string characterSprites, int timerInterval);
    ~Player();
    int getHealth();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getX();
    int getY();
private:
    int health;
    int attack;
    int defense;
    int speed;
    int x;
    int y;
    int currentSprite = 0;
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
