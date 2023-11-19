#include "gamemanager.h"

GameManager::GameManager(QGraphicsView *g)
{
    fLevel = new FirstLevelScene;
    sLevel = new SecondLevelScene;
    mScene = new MenuScene;
    this->g = g;
}

GameManager::~GameManager() {
    delete fLevel;
    delete sLevel;
    delete g;
    delete mScene;
}

void GameManager::showLevelScene(int currentLevelScene)
{
    this->currentLevelScene = currentLevelScene;
    g->setVisible(true);
    g->setWindowTitle("Level " + QString::number(currentLevelScene));

    clearCurrentScene();

    if (currentLevelScene == 1) {
        fLevel->setGraphicsScene(g);
    } else if (currentLevelScene == 2) {
        sLevel->setGraphicsScene(g);
    }
}

void GameManager::showMenu()
{
    clearCurrentScene();
    mScene->setGraphicsScene(g);
}

void GameManager::playerMovement(int pos)
{
    if (currentLevelScene == 1) {
        fLevel->modifyPositionDir(pos);
        fLevel->movePlayer();
    }
}

void GameManager::playerNoMovement()
{
    if (currentLevelScene == 1) {
        fLevel->noMovePlayer();
    }
}

void GameManager::invokeBullet(int x, int y)
{
    if (currentLevelScene == 1) {
        fLevel->generateBullet(x, y);
    }
}

void GameManager::clearCurrentScene()
{
    if (currentLevelScene == 1) {
        fLevel->clearScene();
    } else if (currentLevelScene == 2) {
    }
    if (g->scene()) {
        QList<QGraphicsItem*> items = g->scene()->items();
        for (QGraphicsItem* item : items) {
            g->scene()->removeItem(item);
            delete item;
        }
    }
}
