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
