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
class SecondLevelScene:public QGraphicsScene,public QObject
{
     Q_OBJECT
public:

    SecondLevelScene();
    ~SecondLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movement(char key);
    using QGraphicsScene::connect;
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    QPixmap *background;
    QBrush *brush;
    QPixmap *spr_nave;
    Spacecraft *nave;
    QPixmap *spr_enemy;
    enemies_nave *enemy;
    QTimer *timer_enemy;

private slots:
  void move_enemy();

};



#endif // SECONDLEVELSCENE_H
