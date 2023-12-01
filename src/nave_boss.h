#ifndef NAVE_BOSS_H
#define NAVE_BOSS_H
#include "qgraphicsitem.h"
class nave_boss: public QGraphicsPixmapItem
{
private:
    int health;
    int x;
    int y;
    int speed=5;
    double g=9.8;


public:
    nave_boss();
    nave_boss(int health,int x,int y);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
};

#endif // NAVE_BOSS_H
