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
#include "background.h"
#include <QTimer>
#include <QScrollBar>
#include "enemies_nave.h"
#include <QObject>
#include <stdlib.h>
class SecondLevelScene:public QObject
{
     Q_OBJECT
public:

    SecondLevelScene();
    virtual ~SecondLevelScene();
    //~SecondLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movement(char key);

private:
    QGraphicsView *g;
    QGraphicsScene *s;
    QPixmap *background;
    QBrush *brush;
    QPixmap *spr_nave;
    Spacecraft *nave;
    QPixmap *spr_enemy;
    enemies_nave *enemy;
    QTimer *timer_move_enemy;
    QTimer *timer_enemy;
    QTimer *timer_asteroid;
    QPixmap *spr_asteroid;
    enemies_nave *asteroid;
    QVector<enemies_nave*> enemies;


private slots:
  void move_enemy();
  void generate_enemy();
  void generate_asteroid();

};



#endif // SECONDLEVELSCENE_H
