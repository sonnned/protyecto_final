#ifndef BULLET_H
#define BULLET_H

#include "macros.h"
#include "enemy.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTransform>
#include <QPainter>
#include <QColor>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(int limitOfSprites, std::string bulletSprites, int timerInterval,int level);
    Bullet(int limitOfSprites, std::string bulletSprites, int timerInterval,int level, int xPlayerPos, int yPlayerPos);
    ~Bullet();
    void targetDirection(int dir);
private:
    int limitOfSprites;
    int level;
    int timerInterval;
    int currentSpriteRows = 0;
    std::string bulletSprites;
    QTimer *timer;
    QPixmap *sprite;
    void cutSprite();
    void paintBullet();
    int direction;
    void moveBullet(int opcion);
    int bulletSpeed = 20;
    void deleteBullet();
    void changeSprite(int opcion);
    // factorOfVelocity escala la velocidad a un factor más grande para evitar que el tiro sea en tiempo real
    // y poder aumentar la velocidad de la bala
    float finalXPos, finalYPos, finalVelX, finalVelY, gravity, period, factorOfVelocity;
    unsigned int n;
private slots:
    void connect_change_slot();
};

#endif // BULLET_H
