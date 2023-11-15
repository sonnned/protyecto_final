#include "gamemanager.h"

GameManager::GameManager(Game *g, Ui::Game *ui)
{
    this->g = g;
    this->ui = ui;
    s = new QGraphicsScene;
    s->setSceneRect(0, 0, ui->level_1->width() - 2, ui->level_1->height() - 2);
}

GameManager::~GameManager() {
    delete ui;
    delete s;
    delete mScene;
    delete sScene;
    delete fScene;
    delete player;
    delete background_2;
    delete brocha;
}

void GameManager::changeCurrentScene(int currentView)
{
    if (currentView == 1) {
        s->clear();
        player = new Player(100, 10, 10, 10, 3, playerSprites[0], 1000);
        s->addItem(player);
        ui->graphics_level_1->setScene(s);
        ui->graphics_level_1->setSceneRect(0, 0, ui->level_1->width() - 2, ui->level_1->height() - 2);
        ui->stackedWidget->setCurrentWidget(ui->level_1);
    } else if (currentView == 2) {
        s->clear();
        background_2 = new QPixmap(":/spritres/fondo_espacio.jpg");

        // Create a rectangle item to represent the background
        //QGraphicsRectItem *backgroundRect = new QGraphicsRectItem(0, 0, ui->level_1->width() - 2, ui->level_1->height() - 2);
        brocha = new QBrush(*background_2);
        //backgroundRect->setBrush(*brocha);

        // Add the background rectangle to the scene
        //s->addItem(backgroundRect);
        ui->graphics_level_2->setBackgroundBrush(*brocha);
        ui->graphics_level_2->setScene(s);
        ui->stackedWidget->setCurrentWidget(ui->level_2);

    } else if (currentView == 0){
        s->clear();
        ui->stackedWidget->setCurrentWidget(ui->menu_page);
    }
}

void GameManager::movePlayer(int newX, int newY)
{
    if (checkIsPlayerOnScreen(player->getX() + newX, player->getY() + newY)) {
        player->setIsMoving(true);
        player->setX(player->getX() + newX);
        player->setY(player->getY() + newY);
        player->setPos(player->getX() + newX, player->getY() + newY);
    } else {
        player->setPos(player->getX(), player->getY());
    }
}

bool GameManager::checkIsPlayerOnScreen(int x, int y)
{
    if (x < 0 || x > ui->level_1->width() - 32 || y < 0 || y > ui->level_1->height() - 32) {
        return false;
    }
    return true;
}
