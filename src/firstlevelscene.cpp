#include "firstlevelscene.h"

FirstLevelScene::FirstLevelScene()
{
    s = new QGraphicsScene;
    p = new Player(100, 10, 10, 10, 3, playerSprites[0], 1000);
    enemyTimer = new QTimer;
    enemyTimer->start(3000);
    connect(enemyTimer, &QTimer::timeout, this, &FirstLevelScene::generateEnemy);
}

FirstLevelScene::~FirstLevelScene()
{
    delete s;
    delete g;
    delete p;
}

void FirstLevelScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    s->addItem(p);
    g->setScene(s);
}

void FirstLevelScene::movePlayer()
{
    p->movePlayer();
    p->setIsMoving(true);
}

void FirstLevelScene::noMovePlayer()
{
    p->setIsMoving(false);
}

void FirstLevelScene::modifyPositionDir(int pos)
{
    p->modifyPositionVector(pos);
}

int FirstLevelScene::getXPlayerPos()
{
    return p->getXPos();
}

int FirstLevelScene::getYPlayerPos()
{
    return p->getYPos();
}

void FirstLevelScene::generateEnemy()
{
    int distanceGeneration = 200;
    int angleOfGeneration = rand() % 360;

    int xPos = p->getXPos() + distanceGeneration * std::cos(angleOfGeneration * M_PI / 180);
    int yPos = p->getYPos() + distanceGeneration * std::sin(angleOfGeneration * M_PI / 180);

    xPos = qBound(0, xPos, static_cast<int>(s->width()));
    yPos = qBound(0, yPos, static_cast<int>(s->height()));

    Enemy *newEnemy = new Enemy(100, 10, 10, 10, 3, playerSprites[1], 1000);
    newEnemy->setPos(xPos, yPos);

    connect(p, &Player::changeEnemyPos, newEnemy, &Enemy::changePosition);

    s->addItem(newEnemy);
}
