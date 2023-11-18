#include "secondlevelscene.h"
#include <iostream>



SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background = new QPixmap(":/spritres/backgrounds/fondo_espacio.jpg");
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave_morty.png");
    nave=new Spacecraft(10,200,400);

}

void SecondLevelScene::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        nave->setPos(nave->getX() - nave->getSpeed(), nave->getY());
    }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        nave->setPos(nave->getX() + nave->getSpeed(), nave->getY());
   }


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
    nave->setPos(nave->getX(),nave->getY());

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
