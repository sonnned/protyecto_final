#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "menuscene.h"
#include "firstlevelscene.h"
#include "secondlevelscene.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void set_graphicsview(QGraphicsView *g);
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    MenuScene *mScene;
    FirstLevelScene *fScene;
    SecondLevelScene *sScene;
    //Game manager variables
    bool show_menu = true;
    bool first_game = false;
    bool second_game = false;
private slots:
    void change_scene(int scene);
};

#endif // GAMEMANAGER_H
