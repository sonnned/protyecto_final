#include "game.h"
#include "ui_game.h"
#include "firstlevelscene.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    gManager = new GameManager(this, ui);
    player = new Player(100, 10, 10, 10, 0, 0, 3, ":/spritres/characters/Rick.png", 1000);
    scene = new QGraphicsScene;
    this->setFixedSize(800, 600);
    this->setWindowTitle("Rick and Morty: Final Game");

    scene->addItem(player);

    ui->graphics_level_1->setScene(scene);

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
    delete player;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        if (ui->stackedWidget->currentWidget() != ui->menu_page) {
            ui->stackedWidget->setCurrentWidget(ui->game_menu);
        }
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
    ui->stackedWidget->setCurrentWidget(ui->menu_page);
}

void Game::onBtnContinueClicked()
{
    if (currentPage == 1) {
        ui->stackedWidget->setCurrentWidget(ui->level_1);
    } else if (currentPage == 2) {
        ui->stackedWidget->setCurrentWidget(ui->level_2);
    }
}

