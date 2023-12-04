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
    int amplitude=2;
    int frequency=3;


public:
    nave_boss();
    nave_boss(int health);

    int getHealth() const;
    void setHealth(int newHealth);
    int getAmplitude() const;
    void setAmplitude(int newAmplitude);
    int getFrequency() const;
    void setFrequency(int newFrequency);
};

#endif // NAVE_BOSS_H
