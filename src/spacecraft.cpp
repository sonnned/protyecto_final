#include "spacecraft.h"

Spacecraft::Spacecraft()
{

}

Spacecraft::Spacecraft(int health, int x, int y)
{
    this->health=health;
    this->x = x;
    this->y = y;
}

int Spacecraft::getX() const
{
    return x;
}

void Spacecraft::setX(int newX)
{
    x = newX;
}


int Spacecraft::getY() const
{
    return y;
}

void Spacecraft::setY(int newY)
{
    y = newY;
}

unsigned int Spacecraft::getSpeed() const
{
    return speed;
}

void Spacecraft::setSpeed(unsigned int newSpeed)
{
    speed = newSpeed;
}

bool Spacecraft::collision_right()
{
    if(x>660){
        return true;
    }
    else{
        return false;
    }
}

bool Spacecraft::collision_left()
{
    if(x<0){
        return true;
    }
    else{
        return false;
    }
}

int Spacecraft::getHealth() const
{
    return health;
}

void Spacecraft::setHealth(int newHealth)
{
    health = newHealth;
}




