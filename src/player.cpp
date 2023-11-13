#include "player.h"

Player::Player(int health, int attack, int defense, int speed, int limitOfSprites, std::string characterSprites, int timerInterval)
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
    sprite = new QPixmap;
    this->timer = new QTimer();
    timer->start(timerInterval / 5);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeSprite()));
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

void Player::modifyPositionVector(int pos)
{
    for (int i = 0; i < 4; i++) {
        if (i == pos) movementPosition[i] = 1;
        else movementPosition[i] = 0;
    }
}

void Player::setX(int newX)
{
    x = newX;
}

void Player::setY(int newY)
{
    y = newY;
}

void Player::cutSprite()
{
    QPixmap tempSprite;
    tempSprite.load(QString::fromStdString(characterSprites));
    *sprite = tempSprite.copy(
        (CHARACTER_SPRITE_BORDER * (currentSpriteRows + 1)) + (CHARACTER_WEIGHT * currentSpriteRows)
        , (CHARACTER_SPRITE_START_Y_POSITION + (CHARACTER_SPRITE_BORDER * currentSpriteCols)) + ((CHARACTER_HEIGHT * currentSpriteCols))
        , CHARACTER_WEIGHT, CHARACTER_HEIGHT
    );
}

void Player::changeSprite() {
    if (movementPosition[0] == 1) {
        currentSpriteCols = 2;
    } else if (movementPosition[1] == 1) {
        currentSpriteCols = 0;
    } else if (movementPosition[2] == 1) {
        currentSpriteCols = 1;
    } else if (movementPosition[3] == 1) {
        currentSpriteCols = 1;
    }

    currentSpriteRows++;
    if (currentSpriteRows > limitOfSprites) currentSpriteRows = 0;
    cutSprite();
    setPos(x, y);
    setPixmap(*sprite);

    std::cout << currentSpriteRows << std::endl;
}
