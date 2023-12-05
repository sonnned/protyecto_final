#include "enemies_nave.h"


int enemies_nave::getSpeed() const
{
    return speed;
}

void enemies_nave::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

int enemies_nave::getScroll() const
{
    return scroll;
}

void enemies_nave::setScroll(int newScroll)
{
    scroll = newScroll;
}

enemies_nave::enemies_nave()
{

}

