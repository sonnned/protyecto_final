#ifndef NAVE_BOSS_H
#define NAVE_BOSS_H
#include "qgraphicsitem.h"
class nave_boss: public QObject,public QGraphicsPixmapItem
{
     Q_OBJECT
private:
    int health;

    int speed=5;
    int posI=10;


public:
    nave_boss();
    nave_boss(int health);

    int getHealth() const;
    void setHealth(int newHealth);



    int getPosI() const;
    void setPosI(int newPosI);

signals:
    void change_health_boss();
};

#endif // NAVE_BOSS_H
