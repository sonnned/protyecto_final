#include "game.h"
#include "ui_game.h"
#include "firstlevelscene.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->setWindowTitle("Rick and Morty: Final Game");
    ui->gameGraphics->setFixedSize(800, 600);
    ui->gameGraphics->setVisible(false);

    gManager = new GameManager(ui->gameGraphics);

    connect(ui->pushExitBtn, &QPushButton::clicked, this, &Game::setLeaveGame);
    connect(ui->pushLevel1Btn, &QPushButton::clicked, this, &Game::setFirstLevel);
    connect(ui->pushLevel2Btn, &QPushButton::clicked, this, &Game::setSecondLevel);
}

Game::~Game()
{
    delete ui;
    delete gManager;
}

void Game::changeCurrentPageView()
{
    this->setVisible(false);
    if (currentPage == 1) gManager->showLevelScene(1);
    else if (currentPage == 2) gManager->showLevelScene(2);
    this->show();
}

void Game::setFirstLevel()
{
    currentPage = 1;
    isPlaying = true;
    changeCurrentPageView();

}

void Game::setSecondLevel()
{
    currentPage = 2;
    isPlaying = true;
    changeCurrentPageView();
}

void Game::setLeaveGame() {
    this->close();
}

void Game::keyPressEvent(QKeyEvent *e)
{
    if (isPaused) {
        if (e->key() == Qt::Key_Escape) {
        }
        return;
    }

    if (isPlaying) {
        if (e->key() == Qt::Key_W) {
            gManager->playerMovement(0);
        } else if (e->key() == Qt::Key_S) {
            gManager->playerMovement(1);
        } else if (e->key() == Qt::Key_A) {
            if (currentPage==1) {
                gManager->playerMovement(2);
            } else if (currentPage==2) {
                gManager->NaveMovement('A');
            }
        } else if (e->key() == Qt::Key_D) {
            if (currentPage==1) {
                gManager->playerMovement(3);
            } else if (currentPage==2){
                gManager->NaveMovement('D');
            }
        }
    }
}



void Game::keyReleaseEvent(QKeyEvent *e)
{
     if(currentPage==1){
    if (isPlaying) {
        if (e->key() == Qt::Key_W) {
            gManager->playerNoMovement();
        } else if (e->key() == Qt::Key_S) {
            gManager->playerNoMovement();
        } else if (e->key() == Qt::Key_A) {
            gManager->playerNoMovement();
        } else if (e->key() == Qt::Key_D) {
            gManager->playerNoMovement();
        }
    }
     }
}

void Game::mousePressEvent(QMouseEvent *e)
{
    if (isPlaying) {
        if (e->button() == Qt::LeftButton) {
            int mouseX = e->pos().x();
            int mouseY = e->pos().y();
            gManager->invokeBullet(mouseX, mouseY);
        }
    }
}


