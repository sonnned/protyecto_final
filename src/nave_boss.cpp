#include "nave_boss.h"

int nave_boss::getX() const
{
    return x;
}

void nave_boss::setX(int newX)
{
    x = newX;
}

int nave_boss::getY() const
{
    return y;
}

void nave_boss::setY(int newY)
{
    y = newY;
}

nave_boss::nave_boss()
{

}

nave_boss::nave_boss(int health, int x, int y)
{
    this->health=health;
    this->x = x;
    this->y = y;
}
