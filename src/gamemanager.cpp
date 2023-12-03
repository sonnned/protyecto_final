#include "gamemanager.h"

GameManager::GameManager(QGraphicsView *g)
{
    fLevel = new FirstLevelScene;
    sLevel = new SecondLevelScene;
    mScene = new MenuScene;
    this->g = g;
    timer = new QTimer;
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &GameManager::verifyEndLevelScene);
    connect(timer, &QTimer::timeout, this, &GameManager::verifyIsOver);
}

GameManager::~GameManager() {
    delete fLevel;
    delete sLevel;
    delete mScene;
    delete g;
    delete timer;
}

void GameManager::showLevelScene(int currentLevelScene)
{
    fLevel = new FirstLevelScene;
    this->currentLevelScene = currentLevelScene;
    g->setVisible(true);
    clearCurrentScene();
    if (currentLevelScene == 1) {
        fLevel->setGraphicsScene(g);
        fLevel->startLevel();
    } else if (currentLevelScene == 2) {
        sLevel->setGraphicsScene(g);
        sLevel->startLevel();
    }
}

void GameManager::showMenu()
{
    clearCurrentScene();
    mScene->set_graphicsview(g);
}

void GameManager::playerMovement(int pos)
{
    if (currentLevelScene == 1) {
        fLevel->modifyPositionDir(pos);
        fLevel->movePlayer();
    }
}

void GameManager::NaveMovement(char key)
{
    if(currentLevelScene==2){
        if(key=='A'){
            sLevel->movement('A');
        }
        else if(key=='D')
            sLevel->movement('D');
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
        sLevel->clearScene();
    }
    if (g->scene()) {
        QList<QGraphicsItem*> items = g->scene()->items();
        for (QGraphicsItem* item : items) {
            //g->scene()->removeItem(item);
            //delete item;
        }
    }
}

int GameManager::getCurrentLevelScene() const
{
    return currentLevelScene;
}

void GameManager::verifyEndLevelScene()
{
    if (currentLevelScene == 1) {
        if (fLevel->getDeadEnemies() == 20) {
            g->setVisible(false);
            currentLevelScene = 0;
            clearCurrentScene();
            fLevel->setDeadEnemies(0);
            setIsWon(true);
            setIsDead(false);
        }
    }
}

void GameManager::verifyIsOver()
{
    if (currentLevelScene == 1) {
        if (fLevel->getPlayerLife() <= 0) {
            g->setVisible(false);
            currentLevelScene = 0;
            clearCurrentScene();
            fLevel->setPlayerLife(100);
            setIsWon(false);
            setIsDead(true);
        }
    }
}

bool GameManager::getIsWon() const
{
    return isWon;
}

void GameManager::setIsWon(bool newIsWon)
{
    isWon = newIsWon;
}

bool GameManager::getIsDead() const
{
    return isDead;
}

void GameManager::setIsDead(bool newIsDead)
{
    isDead = newIsDead;
}
