#include "secondlevelscene.h"

SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    spacecraft = new Spacecraft();
    background = new QPixmap(":/spritres/backgrounds/fondo_espacio.jpg");
    brush = new QBrush(*background);
}

SecondLevelScene::~SecondLevelScene()
{
    delete background;
    delete brush;
    delete g;
    delete s;
    delete spacecraft;
}

void SecondLevelScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    g->setBackgroundBrush(*brush);
    g->setScene(s);
}
