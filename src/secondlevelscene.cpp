#include "secondlevelscene.h"
#include <iostream>
#include "enemies_nave.h"

SecondLevelScene::SecondLevelScene()
{
    s = new QGraphicsScene;
    background= new QPixmap();
    brush = new QBrush(*background);
    spr_nave=new QPixmap(":/spritres/characters/nave_morty.png");
    nave=new Spacecraft(10);
    boss=new nave_boss(10);
    spr_boss=new QPixmap(":/spritres/enemies/boss.png");
    timer_collision=new QTimer();
     timer_enemy=new QTimer();
     timer_move_enemy=new QTimer();
     timer_asteroid=new QTimer();
    message=new PlayerScore(QString("vidas: "),0, 5, 600, 25);
    connect(timer_asteroid,SIGNAL(timeout()),this,SLOT(generate_asteroid()));
    connect(timer_enemy,SIGNAL(timeout()),this,SLOT(generate_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_enemy()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_background()));
    connect(timer_move_enemy,SIGNAL(timeout()),this,SLOT(move_boss()));
    connect(timer_enemy,SIGNAL(timeout()),this,SLOT(generate_bullet()));
    connect(timer_collision,SIGNAL(timeout()),this,SLOT(collision_bullet()));
    connect(nave,&Spacecraft::change_healt,message,&::PlayerScore::decrease_healt_spacecraft);

//":/spritres/backgrounds/fondito_prueba.jpg"
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
    s->addItem(message);




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
timer_enemy->start(2000);
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
for (auto it = enemies.begin(); it != enemies.end();) {
        (*it)->setPos((*it)->pos().x(), (*it)->QGraphicsPixmapItem::y() + (*it)->getSpeed());
        (*it)->setY((*it)->y() + (*it)->getSpeed());

        if ((*it)->collidesWithItem(nave)) {
           nave->setHealth(nave->getHealth() - 1);
           s->removeItem(*it);
           delete *it;
           it = enemies.erase(it);
           emit nave->change_healt();
        } else if ((*it)->y() > 600) {
           s->removeItem(*it);
           delete *it;
           it = enemies.erase(it);
        }
        else {
           ++it;
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

boss->setPos(boss->x()+5,boss->y()-2);

if(boss->x()>800){
        boss->setPos(-200,10);

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
for (auto it = bullets.begin(); it != bullets.end();) {
        if ((*it)->y() < posi_bullet) {
           s->removeItem(*it);
           delete *it;
           it = bullets.erase(it);
        } else if ((*it)->collidesWithItem(boss)) {
           s->removeItem(*it);
           delete *it;
           it = bullets.erase(it);
           boss->setHealth(boss->getHealth() - 1);

        }
        else {
           ++it;
        }

        posi_bullet -= scroll;
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
