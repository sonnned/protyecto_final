#ifndef ENEMIES_NAVE_H
#define ENEMIES_NAVE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>

class enemies_nave : public QGraphicsPixmapItem
{

private:
    int x;
    int y;
    int speed=30;
public:
    enemies_nave();
    enemies_nave(int x, int y);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    int getSpeed() const;
    void setSpeed(int newSpeed);
};

#endif // ENEMIES_NAVE_H
