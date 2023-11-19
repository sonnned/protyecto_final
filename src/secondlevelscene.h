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

class SecondLevelScene:public QGraphicsScene
{
public:

    SecondLevelScene();
    ~SecondLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movement(char key);

private:
    QGraphicsView *g;
    QGraphicsScene *s;
    QPixmap *background;
    QBrush *brush;
    QPixmap *spr_nave;
    Spacecraft *nave;

};

#endif // SECONDLEVELSCENE_H
