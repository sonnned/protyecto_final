#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <string>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
class Spacecraft :public QObject, public QGraphicsPixmapItem

{
     Q_OBJECT
public:
    Spacecraft();
    Spacecraft(int health);
    unsigned int getSpeed() const;
    void setSpeed(unsigned int newSpeed);
    bool collision_right();
    bool collision_left();
    int getHealth() const;
    void setHealth(int newHealth);

private:
    int health;
    //int X;
    //int Y;
    unsigned int speed =5;


signals:
    void change_health();
};

#endif // SPACECRAFT_H
