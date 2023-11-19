#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <string>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
class Spacecraft :public QGraphicsPixmapItem
{
public:
    Spacecraft();
    Spacecraft(int health, int x, int y);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    unsigned int getSpeed() const;
    void setSpeed(unsigned int newSpeed);
    bool collision_right();
    bool collision_left();


private:
    int health;
    int x;
    int y;
    unsigned int speed = 7;
};

#endif // SPACECRAFT_H
