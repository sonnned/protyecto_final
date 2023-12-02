#ifndef NAVE_BOSS_H
#define NAVE_BOSS_H
#include "qgraphicsitem.h"
class nave_boss: public QGraphicsPixmapItem
{
private:
    int health;
   // int X;
   // int Y;
    int speed=5;
    double g=9.8;


public:
    nave_boss();
    nave_boss(int health);

    int getHealth() const;
    void setHealth(int newHealth);
};

#endif // NAVE_BOSS_H
