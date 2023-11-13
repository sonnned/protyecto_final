#include "game.h"
#include "ui_game.h"
#include "firstlevelscene.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    gManager = new GameManager(this, ui);
    this->setFixedSize(800, 600);
    this->setWindowTitle("Rick and Morty: Final Game");

    connect(ui->btn_level_1, &QPushButton::clicked, this, &Game::onBtnLevel1Clicked);
    connect(ui->btn_level_2, &QPushButton::clicked, this, &Game::onBtnLevel2Clicked);
    connect(ui->btn_exit_game, &QPushButton::clicked, this, &Game::onBtnExitGameClicked);
    connect(ui->btn_go_back, &QPushButton::clicked, this, &Game::onBtnGoBackClicked);
    connect(ui->btn_continue, &QPushButton::clicked, this, &Game::onBtnContinueClicked);
}

Game::~Game()
{
    delete ui;
    delete gManager;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        if (ui->stackedWidget->currentWidget() != ui->menu_page && ui->stackedWidget->currentWidget() != ui->game_menu) {
            ui->stackedWidget->setCurrentWidget(ui->game_menu);
        }
        else if (ui->stackedWidget->currentWidget() == ui->game_menu) {
            gManager->changeCurrentScene(currentPage);
        }
    }

    if (event->key() == Qt::Key_W) {
        gManager->movePlayer(0, -32);
    } else if (event->key() == Qt::Key_S) {
        gManager->movePlayer(0, 32);
    } else if (event->key() == Qt::Key_A) {
        gManager->movePlayer(-32, 0);
    } else if (event->key() == Qt::Key_D) {
        gManager->movePlayer(32, 0);
    }
}

void Game::onBtnLevel1Clicked()
{
    currentPage = 1;
    gManager->changeCurrentScene(currentPage);
}

void Game::onBtnLevel2Clicked()
{
    currentPage = 2;
    gManager->changeCurrentScene(currentPage);
}

void Game::onBtnExitGameClicked()
{
    this->close();
}

void Game::onBtnGoBackClicked()
{
    currentPage = 0;
    gManager->changeCurrentScene(currentPage);
}

void Game::onBtnContinueClicked()
{
    if (currentPage == 1) {
        ui->stackedWidget->setCurrentWidget(ui->level_1);
    } else if (currentPage == 2) {
        ui->stackedWidget->setCurrentWidget(ui->level_2);
    }
}

