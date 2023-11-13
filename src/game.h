#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "gamemanager.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
private:
    Ui::Game *ui;
    GameManager* gManager;
    void keyPressEvent(QKeyEvent *event);
    int currentPage = 0;
    QGraphicsScene *scene;
    Player *player;
private slots:
    void onBtnLevel1Clicked();
    void onBtnLevel2Clicked();
    void onBtnExitGameClicked();
    void onBtnGoBackClicked();
    void onBtnContinueClicked();
};
#endif // GAME_H
