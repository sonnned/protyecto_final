#ifndef GAME_H
#define GAME_H

#include "gamemanager.h"

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>

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
    int currentPage = 0;
    void changeCurrentPageView();
    bool isPaused = false;
    bool isPlaying = false;
    bool isWon = false;
    QTimer *timer;
    void setWinMenu();
    void setOverMenu();
    void clearMenuScene();
private slots:
    void setFirstLevel();
    void setSecondLevel();
    void setMenu();
    void setLeaveGame();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void verifyMainScene();
    void setHome();
};
#endif // GAME_H
