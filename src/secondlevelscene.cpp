#include "secondlevelscene.h"
#include <iostream>
#include "enemies_nave.h"


SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background= new QPixmap(":/spritres/backgrounds/fondito_largo.jpg");
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave_morty.png");
    nave=new Spacecraft(10,200,400);
     timer_enemy=new QTimer();
     timer_enemy->start(2000);
     timer_move_enemy=new QTimer();
     timer_move_enemy->start(50);
    connect(timer_enemy,SIGNAL(timeout()),this,SLOT(generate_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_enemy()));

}


void SecondLevelScene::setGraphicsScene(QGraphicsView *g)
{
    this->g = g;
    s->setSceneRect(0, 0, g->width() - 2, g->height() - 2);

    g->setBackgroundBrush(*brush);
    g->setScene(s);
    s->addItem(nave);
    nave->setScale(0.4);
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

void SecondLevelScene::move_enemy()
{
for(int i=0;i<enemies.size();i++){
    enemies[i]->setPos(enemies[i]->pos().x(),enemies[i]->pos().y()+enemies[i]->getSpeed());
        enemies[i]->setY(enemies[i]->getY()+enemies[i]->getSpeed());
/*
    if(enemies[i]->getY()>80){
           s->removeItem(enemies[i]);
           delete enemies[i];

        }
*/
}
}




void SecondLevelScene::generate_enemy()
{
//798


spr_enemy=new QPixmap(":/spritres/enemies/nave_enemiga.png");
enemy=new enemies_nave(rand()% 700,0);
enemy->setPixmap(*spr_enemy);
enemy->setPos(enemy->getX(),enemy->getY());
s->addItem(enemy);
amount_enemies++;
enemies.push_back(enemy);










}

SecondLevelScene::~SecondLevelScene()
{
    delete background;
    delete brush;
    delete g;
    delete s;
    delete nave;
    delete spr_nave;
    delete spr_enemy;
    delete enemy;
    delete timer_enemy;

}
