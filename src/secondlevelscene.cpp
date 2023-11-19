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

void SecondLevelScene::movement(char key)
{
    if(key=='A'){
        if(nave->collision_left()==true){
            nave->setPos(nave->pos().x()+0,nave->pos().y());
            nave->setX(nave->getX()+0);
        }
        else{
           nave->setPos(nave->pos().x()-nave->getSpeed(),nave->pos().y());
           nave->setX(nave->getX()-nave->getSpeed());
        }

    }
    if(key=='D'){

        if(nave->collision_right()==true){
           nave->setPos(nave->pos().x()+0,nave->pos().y());
           nave->setX(nave->getX()+0);
        }
        else{
           nave->setPos(nave->pos().x()+nave->getSpeed(),nave->pos().y());
           nave->setX(nave->getX()+nave->getSpeed());
        }

}

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
