#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QKeyEvent>
#include "gamemanager.h"

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
private slots:
    void setFirstLevel();
    void setSecondLevel();
    void setLeaveGame();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
};
#endif // GAME_H
