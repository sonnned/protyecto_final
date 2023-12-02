#include "spacecraft.h"

Spacecraft::Spacecraft()
{

}

Spacecraft::Spacecraft(int health)
{
    this->health=health;

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
    if(x()>660){
        return true;
    }
    else{
        return false;
    }
}

bool Spacecraft::collision_left()
{
    if(x()<0){
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




