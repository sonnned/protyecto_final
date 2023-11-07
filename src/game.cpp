#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    mScene = new MenuScene;
    mScene->set_graphicsview(ui->main_scene);
    this->setFixedSize(800, 600);
    this->setWindowTitle("Rick and Morty: Final Game");
}

Game::~Game()
{
    delete ui;
    delete mScene;
}

