#include "spacecraft.h"

Spacecraft::Spacecraft()
{

}

Spacecraft::Spacecraft(int health, int x, int y, QPixmap *sprite)
{
    this->health = health;
    this->x = x;
    this->y = y;
}
