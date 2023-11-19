#include "gamemanager.h"

GameManager::GameManager(QGraphicsView *g)
{
    fLevel = new FirstLevelScene;
    sLevel = new SecondLevelScene;
    this->g = g;
}

GameManager::~GameManager() {
    delete fLevel;
    delete sLevel;
    delete g;
}

void GameManager::showLevelScene(int currentLevelScene)
{
    this->currentLevelScene = currentLevelScene;
    g->setVisible(true);
    g->setWindowTitle("l1");
    if (currentLevelScene == 1) {
        fLevel->setGraphicsScene(g);
    } else if (currentLevelScene == 2) {
        sLevel->setGraphicsScene(g);
    }
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

