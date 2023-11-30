#include "firstlevelscene.h"

FirstLevelScene::FirstLevelScene()
{
    setUpLevel();
}

FirstLevelScene::~FirstLevelScene()
{
    delete s;
    delete g;
    delete p;
    delete enemyTimer;
    delete pScoreEnemies;
    delete pScoreLife;
    delete bulletTimer;
    delete backgroundItem;
    delete pCurrentBullets;
}

void FirstLevelScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    s->addItem(p);
    s->addItem(pScoreEnemies);
    s->addItem(pScoreLife);
    s->addItem(pCurrentBullets);
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

void FirstLevelScene::clearScene()
{
    //s->clear();
    enemyTimer->stop();
}

void FirstLevelScene::generateBullet(int x, int y)
{
    if (amountOfBullets < 4) {
        Bullet *newBullet = new Bullet(1, playerSprites[3], 1000);
        newBullet->setPos(p->getXPos() + (CHARACTER_WEIGHT / 4), p->getYPos() + (CHARACTER_HEIGHT / 4));
        int dir = p->getDir(); // 0 -> UP/1 -> DOWN/2 -> LEFT/3 -> RIGHT
        newBullet->targetDirection(dir);
        s->addItem(newBullet);
        amountOfBullets++;
        p->setCurrentBullets(p->getCurrentBullets() - 1);
    }
    if (bulletTimer->remainingTime() == -1 && amountOfBullets == 4) {
        bulletTimer->start(2000);
        connect(bulletTimer, &QTimer::timeout, this, &FirstLevelScene::shootBullet);
    }
}

void FirstLevelScene::startLevel()
{
    enemyTimer->start(1000);
    amountOfEnemies = 0;
    deadEnemies = 0;
}

int FirstLevelScene::getDeadEnemies() const
{
    return deadEnemies;
}

void FirstLevelScene::setUpLevel()
{
    s = new QGraphicsScene;
    p = new Player(100, 10, 10, 10, 3, playerSprites[0], 1000);
    p->setPos(400 - 125 / 2, 300 - 162 / 2);
    pScoreLife = new PlayerScore(QString("Life: "), 100, 100, 600, 5);
    pScoreEnemies = new PlayerScore(QString("Enemies: "), 20, 0, 600, 25);
    pCurrentBullets = new PlayerScore(QString("Bullets: "), 4, 4, 600, 45);
    enemyTimer = new QTimer;
    this->bulletTimer = new QTimer;
    setBackground();
    connect(enemyTimer, &QTimer::timeout, this, &FirstLevelScene::generateEnemy);
    connect(p, &Player::changePlayerLife, pScoreLife, &PlayerScore::decreaseCurrentPlayerLife);
    connect(p, &Player::changeCurrentBullets, pCurrentBullets, &PlayerScore::changeCurrentBullets);
}

void FirstLevelScene::setDeadEnemies(int newDeadEnemies)
{
    deadEnemies = newDeadEnemies;
}

void FirstLevelScene::setBackground()
{
    backgroundItem = new QGraphicsPixmapItem(QPixmap(QString::fromStdString(background)));
    s->addItem(backgroundItem);
}

void FirstLevelScene::generateEnemy()
{
    if (amountOfEnemies < 5) {
        int distanceGeneration = 200;
        int angleOfGeneration = rand() % 360;

        int xPos = p->getXPos() + distanceGeneration * std::cos(angleOfGeneration * M_PI / 180);
        int yPos = p->getYPos() + distanceGeneration * std::sin(angleOfGeneration * M_PI / 180);

        xPos = qBound(0, xPos, static_cast<int>(s->width()));
        yPos = qBound(0, yPos, static_cast<int>(s->height()));

        int id = 1 + rand() % 2;
        Enemy *newEnemy = new Enemy(p->getXPos(), p->getYPos(), id * 100, 10, 10, (enemyVel / 2) + (rand() % enemyVel), 3, playerSprites[id], 1000);
        newEnemy->setPos(xPos, yPos);
        amountOfEnemies++;

        connect(p, &Player::changeEnemyPos, newEnemy, &Enemy::changePosition);
        connect(newEnemy, &Enemy::enemyIsDeath, this, &FirstLevelScene::amountOfEnemiesDecrement);
        connect(newEnemy, &Enemy::enemyIsDeath, pScoreEnemies, &PlayerScore::increaseCurrentDeadEnemies);
        s->addItem(newEnemy);
    }
}

void FirstLevelScene::amountOfEnemiesDecrement()
{
    amountOfEnemies--;
    deadEnemies++;
    enemyVel += 4;
}

void FirstLevelScene::shootBullet()
{
    amountOfBullets = 0;
    p->setCurrentBullets(4);
    bulletTimer->stop();
}
