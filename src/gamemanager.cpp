#include "gamemanager.h"

GameManager::GameManager(Game *g, Ui::Game *ui)
{
    this->g = g;
    this->ui = ui;
    s = new QGraphicsScene;
    mScene = new MenuScene;
    fScene = new FirstLevelScene;
    sScene = new SecondLevelScene;
}

GameManager::~GameManager() {
    delete ui;
    delete s;
    delete mScene;
    delete sScene;
    delete fScene;
}

void GameManager::changeCurrentScene(int currentView)
{
    if (currentView == 1) {
        ui->stackedWidget->setCurrentWidget(ui->level_1);
    } else if (currentView == 2) {
        ui->stackedWidget->setCurrentWidget(ui->level_2);
    }
}
