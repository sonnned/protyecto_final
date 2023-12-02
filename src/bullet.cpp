#include "bullet.h"

Bullet::Bullet(int limitOfSprites, std::string bulletSprites, int timerInterval,int nevel)
{
    this->limitOfSprites = limitOfSprites;
    this->bulletSprites = bulletSprites;
    this->timerInterval = timerInterval;
    this->nevel=nevel;
    sprite = new QPixmap;
    this->timer = new QTimer();
    timer->start(timerInterval / 10);
    connect(timer, SIGNAL(timeout()), this, SLOT(connect_change_slot()));
}

Bullet::~Bullet()
{
    delete timer;
    delete sprite;
}

void Bullet::targetDirection(int dir)
{
    direction = dir;
    cutSprite();
}

void Bullet::cutSprite()
{
    QPixmap tempSprite;
    tempSprite.load(QString::fromStdString(bulletSprites));
    *sprite = tempSprite.copy(
        BULLET_SIZE * (currentSpriteRows)
        , 0
        , BULLET_SIZE
        , BULLET_SIZE
        );
    paintBullet();
    *sprite = sprite->scaled(20, 20, Qt::KeepAspectRatio);
}

void Bullet::changeSprite(int opcion)
{
    currentSpriteRows++;
    if (currentSpriteRows > limitOfSprites) currentSpriteRows = 0;
    cutSprite();
    setPixmap(*sprite);
    moveBullet(opcion);
}

void Bullet::connect_change_slot()
{
    if(nevel==1){
        changeSprite(1);
    }
    if(nevel==2){
        changeSprite(2);

    }
}

void Bullet::moveBullet(int opcion)
{

    if (direction == 0) {
        setY(y() - bulletSpeed);
    } else if (direction == 1) {
        setY(y() + bulletSpeed);
    } else if (direction == 2) {
        setX(x() - bulletSpeed);
    } else if (direction == 3) {
        setX(x() + bulletSpeed);
    }
    if(opcion==1){
    deleteBullet();
    }


}




void Bullet::deleteBullet()
{

    if ((x() < 0) || (x() > scene()->width()) || (y() < 0) || (y() > scene()->height())) {
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::paintBullet() {
    QPainter painter(sprite);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(sprite->rect(), Qt::green);
    painter.end();
}
