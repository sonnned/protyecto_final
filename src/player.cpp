#include "player.h"

Player::Player(int health, int attack, int defense, int speed, int x, int y, int limitOfSprites, std::string characterSprites, int timerInterval)
{
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->x = x;
    this->y = y;
    this->limitOfSprites = limitOfSprites;
    this->characterSprites = characterSprites;
    this->timerInterval = timerInterval;
    this->timer = new QTimer();
}

Player::~Player()
{
    delete timer;
    delete sprite;
}

int Player::getHealth()
{
    return health;
}

int Player::getAttack()
{
    return attack;
}

int Player::getDefense()
{
    return defense;
}

int Player::getSpeed()
{
    return speed;
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

void Player::cutSprite()
{
    QPixmap tempSprite;
    tempSprite.load(QString::fromStdString(characterSprites));
    *sprite = tempSprite.copy(currentSprite * 32, 0, 32, 32);
}

void Player::changeSprite() {
    currentSprite++;
    if (currentSprite >= limitOfSprites) currentSprite = 0;
    cutSprite();
    setPixmap(*sprite);
}