#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QPixmap>

class Spacecraft
{
public:
    Spacecraft();
    Spacecraft(int health, int x, int y, QPixmap *sprite);
private:
    int health;
    int x;
    int y;
    QPixmap *sprite;
};

#endif // SPACECRAFT_H
