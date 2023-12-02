#include "secondlevelscene.h"
#include <iostream>
#include "enemies_nave.h"

SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background= new QPixmap(":/spritres/backgrounds/fondito_largo.jpg");
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave_morty.png");
    nave=new Spacecraft(10);
    boss=new nave_boss(2);
    spr_boss=new QPixmap(":/spritres/enemies/boss.png");
    timer_collision=new QTimer();
     timer_enemy=new QTimer();
     timer_move_enemy=new QTimer();
     timer_asteroid=new QTimer();
    message=new PlayerScore(QString("vidas: "), 20, 0, 600, 25);
    connect(timer_asteroid,SIGNAL(timeout()),this,SLOT(generate_asteroid()));
    connect(timer_enemy,SIGNAL(timeout()),this,SLOT(generate_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_background()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_boss()));
    connect(timer_asteroid,SIGNAL(timeout()),this,SLOT(generate_bullet()));
     connect(timer_collision,SIGNAL(timeout()),this,SLOT(collision_bullet()));
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
    nave->setPos(200,450);

    s->addItem(boss);
    boss->setScale(0.8);
    boss->setPixmap(*spr_boss);
    boss->setPos(-100,10);




}

void SecondLevelScene::movement(char key)
{
    if(key=='A'){
        if(nave->collision_left()==true){
            nave->setPos(nave->pos().x()+0,nave->pos().y());
            nave->setX(nave->x()+0);
        }
        else{
           nave->setPos(nave->pos().x()-nave->getSpeed(),nave->pos().y());
           nave->setX(nave->x()-nave->getSpeed());
        }

    }
    if(key=='D'){

        if(nave->collision_right()==true){
           nave->setPos(nave->pos().x()+0,nave->pos().y());
           nave->setX(nave->x()+0);
        }
        else{
           nave->setPos(nave->pos().x()+nave->getSpeed(),nave->pos().y());
           nave->setX(nave->x()+nave->getSpeed());
        }

}

}

void SecondLevelScene::startLevel()
{
timer_enemy->start(4000);
timer_move_enemy->start(50);
timer_asteroid->start(1000);
timer_collision->start();

}

void SecondLevelScene::clearScene()
{
timer_enemy->stop();
timer_move_enemy->stop();
timer_asteroid->stop();
timer_collision->stop();

}


void SecondLevelScene::move_enemy()
{

for(int i=0;i<enemies.size();i++){
        enemies[i]->setPos(enemies[i]->pos().x(),enemies[i]->QGraphicsPixmapItem::y()+enemies[i]->getSpeed());
        enemies[i]->setY(enemies[i]->y()+enemies[i]->getSpeed());

        if(enemies[i]->collidesWithItem(nave)){
           nave->setHealth(nave->getHealth()-1);


        }
        if(enemies[i]->y()>600){
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
enemy=new enemies_nave();
enemy->setPixmap(*spr_enemy);
enemy->setPos(rand()%700,posi_enemy);
posi_enemy+=enemy->getScroll()-40;
s->addItem(enemy);
enemies.push_back(enemy);


}

void SecondLevelScene::generate_asteroid()
{

spr_asteroid=new QPixmap(":/spritres/enemies/asteroide.png");
asteroid=new enemies_nave();
asteroid->setPixmap(*spr_asteroid);
asteroid->setPos(rand()%700,posi_ast);
posi_ast+=asteroid->getScroll();
s->addItem(asteroid);
asteroid->setScale(0.3);
enemies.push_back(asteroid);

}

void SecondLevelScene::move_background()
{
nave->setPos(nave->x(),nave->y()-scroll);
s->setSceneRect(0,nave->y()-450,s->width(),s->height());

}

void SecondLevelScene::move_boss()
{

boss->setPos(boss->x()+5,boss->y()-scroll);

if(boss->x()>800){
      boss->setPos(-200,boss->y());
}
if(boss->getHealth()==0){
     boss->setPos(-200,boss->y()-200);
}

}

void SecondLevelScene::generate_bullet()
{
projectile=new Bullet(1,":/spritres/enemies/car/Projectile.png", 1000,2);
projectile->setPos(nave->x() + (CHARACTER_WEIGHT / 4), nave->y() + (CHARACTER_HEIGHT / 4));
int dir = 0;
projectile->targetDirection(dir);
s->addItem(projectile);
bullets.push_back(projectile);

}

void SecondLevelScene::collision_bullet()
{
for(int i=0;i<bullets.size();i++){


      if((bullets[i]->y()<posi_bullet)){
           s->removeItem(bullets[i]);
           delete bullets[i];
           bullets.erase(std::remove(bullets.begin(), bullets.end(), bullets[i]), bullets.end());
        i--;
     }
      else if(bullets[i]->collidesWithItem(boss)){
        s->removeItem(bullets[i]);
        delete bullets[i];
        bullets.erase(std::remove(bullets.begin(), bullets.end(), bullets[i]), bullets.end());
        i--;
        boss->setHealth(boss->getHealth()-1);
      }


      posi_bullet-=scroll;


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
    delete spr_enemy;
    delete enemy;
    delete asteroid;
    delete timer_enemy;
    delete boss;
    delete projectile;

}
