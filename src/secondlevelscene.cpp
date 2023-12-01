#include "secondlevelscene.h"
#include <iostream>
#include "enemies_nave.h"
int posi_ast=-100;
int posi_enemy=-150;
SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background= new QPixmap(":/spritres/backgrounds/fondito_largo.jpg");
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave_morty.png");
    nave=new Spacecraft(10,200,400);
     timer_enemy=new QTimer();
     timer_move_enemy=new QTimer();
     timer_asteroid=new QTimer();

    connect(timer_asteroid,SIGNAL(timeout()),this,SLOT(generate_asteroid()));
    connect(timer_enemy,SIGNAL(timeout()),this,SLOT(generate_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_background()));


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
    //scroll=s->addRect(40,30,30,30,);



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

void SecondLevelScene::startLevel()
{
timer_enemy->start(4000);
timer_move_enemy->start(50);
timer_asteroid->start(1000);

}

void SecondLevelScene::clearScene()
{
timer_enemy->stop();
timer_move_enemy->stop();
timer_asteroid->stop();

}


void SecondLevelScene::move_enemy()
{

for(int i=0;i<enemies.size();i++){
        enemies[i]->setPos(enemies[i]->pos().x(),enemies[i]->QGraphicsPixmapItem::y()+enemies[i]->getSpeed());
        enemies[i]->setY(enemies[i]->getY()+enemies[i]->getSpeed());

        if(enemies[i]->getY()>600){
           s->removeItem(enemies[i]);
           delete enemies[i];
           enemies.erase(std::remove(enemies.begin(), enemies.end(), enemies[i]), enemies.end());
           i--;
        }


}
}




void SecondLevelScene::generate_enemy()
{
//798


spr_enemy=new QPixmap(":/spritres/enemies/nave_enemiga.png");
enemy=new enemies_nave(rand()% 700,posi_enemy);
posi_enemy+=enemy->getScroll()-6;
enemy->setPixmap(*spr_enemy);
enemy->setPos(enemy->getX(),enemy->getY());
s->addItem(enemy);
enemies.push_back(enemy);


}

void SecondLevelScene::generate_asteroid()
{

spr_asteroid=new QPixmap(":/spritres/enemies/asteroide.png");
asteroid=new enemies_nave(rand()% 700,posi_ast);
posi_ast+=asteroid->getScroll();
asteroid->setPixmap(*spr_asteroid);
asteroid->setPos(asteroid->getX(),asteroid->getY());
s->addItem(asteroid);
asteroid->setScale(0.3);
enemies.push_back(asteroid);

}

void SecondLevelScene::move_background()
{
nave->setPos(nave->getX(),nave->QGraphicsPixmapItem::y()-2);
s->setSceneRect(0,nave->QGraphicsPixmapItem::y()-400,s->width(),s->height());

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
