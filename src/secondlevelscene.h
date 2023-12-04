#ifndef SECONDLEVELSCENE_H
#define SECONDLEVELSCENE_H
#include "QGraphicsPixmapItem"
#include "spacecraft.h"
#include <QKeyEvent>
#include <iostream>
#include <vector>
#include <string>
#include <QPixmap>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include <QScrollBar>
#include "enemies_nave.h"
#include <QObject>
#include <stdlib.h>
#include "playerscore.h"
#include "nave_boss.h"
#include "bullet.h"
#include <cmath>//>
class SecondLevelScene:public QObject
{
     Q_OBJECT
public:

    SecondLevelScene();
    virtual ~SecondLevelScene();
    //~SecondLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movement(char key);
    void startLevel();
    void clearScene();

    int getPos() const;
    void setPos(int newPos);

private:
    QGraphicsView *g;
    QGraphicsScene *s;
    QPixmap *background;
    QBrush *brush;
    QPixmap *spr_nave;
    Spacecraft *nave;
    QPixmap *spr_enemy;
    enemies_nave *enemy;
    nave_boss *boss;
    QPixmap *spr_boss;
    QTimer *timer_move_enemy;
    QTimer *timer_enemy;
    QTimer *timer_asteroid;
    QTimer *timer_collision;
    QPixmap *spr_asteroid;
    enemies_nave *asteroid;
    QVector<enemies_nave*> enemies;
    int posi_ast=-100;
    int posi_enemy=-150;
    int posi_bullet=0;
    PlayerScore *message_nave;
    PlayerScore *message_boss;
    Bullet *projectile;
     QVector<Bullet*> bullets;
    int scroll=2;

private slots:
  void move_enemy();
  void generate_enemy();
  void generate_asteroid();
  void move_background();
  void move_boss();
  void generate_bullet();
  void collision_bullet();

};




#endif // SECONDLEVELSCENE_H
