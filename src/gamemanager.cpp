#include "gamemanager.h"

GameManager::GameManager(Game *g, Ui::Game *ui)
{
    this->g = g;
    this->ui = ui;
    s = new QGraphicsScene;
}

GameManager::~GameManager() {
    delete ui;
    delete s;
    delete mScene;
    delete sScene;
    delete fScene;
    delete player;
}

void GameManager::changeCurrentScene(int currentView)
{
    if (currentView == 1) {
        s->clear();
        player = new Player(100, 10, 10, 10, 3, playerSprites[0], 1000);
        s->addItem(player);
        ui->graphics_level_1->setScene(s);
        ui->stackedWidget->setCurrentWidget(ui->level_1);
    } else if (currentView == 2) {
        s->clear();
        ui->stackedWidget->setCurrentWidget(ui->level_2);
    } else if (currentView == 0){
        s->clear();
        ui->stackedWidget->setCurrentWidget(ui->menu_page);
    }
}

void GameManager::movePlayer(int newX, int newY)
{
    if (checkIsPlayerOnScreen(player->getX() + newX, player->getY() + newY)) {
        player->setX(player->getX() + newX);
        player->setY(player->getY() + newY);
        player->setPos(player->getX() + newX, player->getY() + newY);
    } else {
        player->setPos(player->getX(), player->getY());
    }
}

bool GameManager::checkIsPlayerOnScreen(int x, int y)
{
    if (x < 0 || x > 800 || y < 0 || y > 600) {
        return false;
    }
    return true;
}
