#include "player.h"

Player::Player(int health, int attack, int defense, int speed, int limitOfSprites, std::string characterSprites, int timerInterval)
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

int Player::getXPos()
{
    return this->x();
}

int Player::getYPos()
{
    return this->y();
}

void Player::modifyPositionVector(int pos)
{
    for (int i = 0; i < 4; i++) {
        if (i == pos) movementPosition[i] = 1;
        else movementPosition[i] = 0;
    }
}

void Player::setIsMoving(bool newIsMoving)
{
    is_moving = newIsMoving;
}

void Player::movePlayer()
{
    if (movementPosition[0] == 1) {
        setPos(this->x(), this->y() - 4);
        if (this->y() < 0) setPos(this->x(), this->y() + 4);
        if (this->x() > 520 && this->y() < 60) setPos(this->x(), 60);
    }
    else if (movementPosition[1] == 1) {
        setPos(this->x(), this->y() + 4);
        if (this->y() > 516) setPos(this->x(), 516);
    }
    else if (movementPosition[2] == 1) {
        setPos(this->x() - 4, this->y());
        if (this->x() < 0) setPos(this->x() + 4, this->y());
    }
    else if (movementPosition[3] == 1) {
        setPos(this->x() + 4, this->y());
        if (this->x() > 736) setPos(736, this->y());
        if (this->x() > 520 && this->y() < 60) setPos(520, this->y());
    }
}

int Player::getDir()
{
    for (int i = 0; i < 4; i++) {
        if (movementPosition[i] == 1) {
            return i;
        }
    }
}

int Player::getCurrentBullets() const
{
    return currentBullets;
}

void Player::setCurrentBullets(int newCurrentBullets)
{
    currentBullets = newCurrentBullets;
    emit changeCurrentBullets(currentBullets);
}

void Player::cutSprite()
{
    QPixmap tempSprite;
    tempSprite.load(QString::fromStdString(characterSprites));
    *sprite = tempSprite.copy(
        (CHARACTER_SPRITE_BORDER * (currentSpriteRows + 1)) + (CHARACTER_WEIGHT * currentSpriteRows)
        , CHARACTER_SPRITE_START_Y_POSITION + (CHARACTER_HEIGHT * currentSpriteCols) + (CHARACTER_SPRITE_BORDER * (currentSpriteCols + 1))
        , CHARACTER_WEIGHT
        , CHARACTER_HEIGHT
    );
    *sprite = sprite->scaled(CHARACTER_SCALED, CHARACTER_SCALED, Qt::KeepAspectRatio);
}

void Player::checkCollitions()
{
    collitions = collidingItems();

    for (int i = 0; i < collitions.length(); i++) {
        if (typeid(*(collitions[i])) == typeid(Enemy)) {
            health -= 5;
            emit changePlayerLife();
        }
    }
}

void Player::changeSprite() {
    if (movementPosition[0] == 1) {
        currentSpriteCols = 2;
    } else if (movementPosition[1] == 1) {
        currentSpriteCols = 0;
    } else if (movementPosition[2] == 1) {
        currentSpriteCols = 1;
    } else if (movementPosition[3] == 1) {
        currentSpriteCols = 3;
    }
    if (is_moving) {
        emit changeEnemyPos(this->x(), this->y());
        currentSpriteRows++;
        if (currentSpriteRows > limitOfSprites) currentSpriteRows = 0;
    }
    cutSprite();
    setPixmap(*sprite);
    checkCollitions();
}
