#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <string>>
#include <QPixmap>
#include <QGraphicsPixmapItem>
class Spacecraft :public QGraphicsPixmapItem
{
public:
    Spacecraft();
    Spacecraft(int health, int x, int y);
private:
    int health;
    int x;
    int y;
};

#endif // SPACECRAFT_H
