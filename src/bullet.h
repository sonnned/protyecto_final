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
    Bullet(int limitOfSprites, std::string bulletSprites, int timerInterval);
    ~Bullet();
    void targetDirection(int dir);
private:
    int initialVelX;
    int initialVelY;
    int limitOfSprites;
    int timerInterval;
    int currentSpriteRows = 0;
    std::string bulletSprites;
    QTimer *timer;
    QPixmap *sprite;
    void cutSprite();
    void paintBullet();
    int direction;
    void moveBullet();
    int bulletSpeed = 20;
    void deleteBullet();
private slots:
    void changeSprite();
};

#endif // BULLET_H
