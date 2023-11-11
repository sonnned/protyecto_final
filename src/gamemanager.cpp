#include "gamemanager.h"

GameManager::GameManager()
{
    s = new QGraphicsScene;
    mScene = new MenuScene;
    fScene = new FirstLevelScene;
    sScene = new SecondLevelScene;
}

GameManager::~GameManager() {
    delete g;
    delete s;
    delete mScene;
    delete sScene;
    delete fScene;
}

void GameManager::set_graphicsview(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    //s->addItem(mScene);

    //g->setScene(s);
}


void GameManager::change_scene(int scene)
{
/*    if (scene == 1) {
        show_menu = false;
        first_game = true;
        second_game = false;
        s->removeItem(mScene);
        s->addItem(fScene);
        //fScene->start_game();
    }
    else if (scene == 2) {
        show_menu = false;
        first_game = false;
        second_game = true;

        s->removeItem(mScene);
        s->addItem(sScene);
        //sScene->start_game();
    }
    else if (scene == 3) {
        if (first_game) {
            s->removeItem(fScene);
            s->addItem(mScene);
            first_game = false;
            second_game = false;
            show_menu = true;
        }
        else if (second_game) {
            s->removeItem(sScene);
            s->addItem(mScene);
            second_game = false;
            first_game = false;
            show_menu = true;
        }
    }
*/
}
