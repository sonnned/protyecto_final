#include "secondlevelscene.h"

SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background = new QPixmap(":/spritres/backgrounds/fondo_espacio_jpg");
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave rick_and morty.png");
    nave=new Spacecraft();


}

SecondLevelScene::~SecondLevelScene()
{
    delete background;
    delete brush;
    delete g;
    delete s;
    delete nave;
    delete spr_nave;
}

void SecondLevelScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);
    g->setBackgroundBrush(*brush);
    g->setScene(s);
    s->addItem(nave);
    nave->setScale(0.5);
    nave->setPixmap(*spr_nave);
     nave->setPos(200,200);

}
