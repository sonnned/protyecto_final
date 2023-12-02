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
    Bullet(int limitOfSprites, std::string bulletSprites, int timerInterval,int nevel);

    ~Bullet();
    void targetDirection(int dir);
private:
    int initialVelX;
    int initialVelY;
    int limitOfSprites;
    int nevel;
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
private slots:

    void connect_change_slot();
};

#endif // BULLET_H
