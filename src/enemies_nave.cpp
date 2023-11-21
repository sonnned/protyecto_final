#include "enemies_nave.h"

int enemies_nave::getX() const
{
    return x;
}

void enemies_nave::setX(int newX)
{
    x = newX;
}

int enemies_nave::getY() const
{
    return y;
}

void enemies_nave::setY(int newY)
{
    y = newY;
}


int enemies_nave::getSpeed() const
{
    return speed;
}

void enemies_nave::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

enemies_nave::enemies_nave()
{

}

enemies_nave::enemies_nave(int x, int y)
{
    this->x = x;
    this->y = y;
}


