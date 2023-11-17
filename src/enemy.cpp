#include "enemy.h"

Enemy::Enemy(int health, int attack, int defense, int speed, int limitOfSprites, std::string characterSprites, int timerInterval)
{
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->limitOfSprites = limitOfSprites;
    this->characterSprites = characterSprites;
    this->timerInterval = timerInterval;
    sprite = new QPixmap;
    this->timer = new QTimer();
    timer->start(timerInterval / 10);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeSprite()));
}
Enemy::~Enemy()
{
    delete timer;
    delete sprite;
}

void Enemy::setIsMoving(bool newIsMoving)
{
    is_moving = newIsMoving;
}

void Enemy::cutSprite()
{
    QPixmap tempSprite;
    tempSprite.load(QString::fromStdString(characterSprites));
    *sprite = tempSprite.copy(
        ENEMY_SIZE * (currentSpriteRows)
        , 0
        , ENEMY_SIZE
        , ENEMY_SIZE
        );
    *sprite = sprite->scaled(CHARACTER_SCALED, CHARACTER_SCALED, Qt::KeepAspectRatio);
}

void Enemy::followPlayer(int playerX, int playerY)
{
    int dirX = playerX - x();
    int dirY = playerY - y();

    if (abs(dirX) > abs(dirY)) {
        if (dirX > 0) setPos(x() + 2, y());
        else setPos(x() - 2, y());
    } else {
        if (dirY > 0) setPos(x(), y() + 2);
        else setPos(x(), y() - 2);
    }
}

void Enemy::changeSprite() {
    if (is_moving) {
        followPlayer(targetX, targetY);
        currentSpriteRows++;
        if (currentSpriteRows > limitOfSprites) currentSpriteRows = 0;
    }
    cutSprite();

    setPixmap(*sprite);
}

void Enemy::changePosition(int x, int y)
{
    targetX = x;
    targetY = y;
}

