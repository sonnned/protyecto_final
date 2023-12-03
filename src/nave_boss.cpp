#include "nave_boss.h"


int nave_boss::getHealth() const
{
    return health;
}

void nave_boss::setHealth(int newHealth)
{
    health = newHealth;
}

int nave_boss::getAmplitude() const
{
    return amplitude;
}

void nave_boss::setAmplitude(int newAmplitude)
{
    amplitude = newAmplitude;
}

int nave_boss::getFrequency() const
{
    return frequency;
}

void nave_boss::setFrequency(int newFrequency)
{
    frequency = newFrequency;
}

nave_boss::nave_boss()
{

}

nave_boss::nave_boss(int health)
{
    this->health=health;
}
