#include <iostream>
#include "menuscene.h"

MenuScene::MenuScene()
{
    s = new QGraphicsScene;
}

MenuScene::~MenuScene() {
    delete s;
    delete g;
}

void MenuScene::set_graphicsview(QGraphicsView *g)
{
    std::cout << g->width() << std::endl;
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    g->setScene(s);
}


