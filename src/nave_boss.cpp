#include "nave_boss.h"


int nave_boss::getHealth() const
{
    return health;
}

void nave_boss::setHealth(int newHealth)
{
    health = newHealth;
}


int nave_boss::getPosI() const
{
    return posI;
}

void nave_boss::setPosI(int newPosI)
{
    posI = newPosI;
}

nave_boss::nave_boss()
{

}

nave_boss::nave_boss(int health)
{
    this->health=health;
}
