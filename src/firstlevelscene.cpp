#include "firstlevelscene.h"

FirstLevelScene::FirstLevelScene()
{
    s = new QGraphicsScene;
    p = new Player(100, 10, 10, 10, 3, playerSprites[0], 1000);
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
