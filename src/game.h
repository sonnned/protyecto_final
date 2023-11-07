#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "menuscene.h"

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
    MenuScene *mScene;
};
#endif // GAME_H
