#ifndef ENEMIES_NAVE_H
#define ENEMIES_NAVE_H
#include <QGraphicsPixmapItem>
#include <QPixmap>

class enemies_nave : public QGraphicsPixmapItem
{

private:
   // int X;
   // int Y;
    int speed=3;
    int scroll=-100;
public:
    enemies_nave();
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getScroll() const;
    void setScroll(int newScroll);
};

#endif // ENEMIES_NAVE_H
