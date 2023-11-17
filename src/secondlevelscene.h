#ifndef SECONDLEVELSCENE_H
#define SECONDLEVELSCENE_H

#include <spacecraft.h>

#include <iostream>
#include <vector>
#include <string>
#include <QPixmap>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsView>

class SecondLevelScene
{
public:
    SecondLevelScene();
    ~SecondLevelScene();
    void setGraphicsScene(QGraphicsView *g);
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    QPixmap *background;
    QBrush *brush;
    Spacecraft *spacecraft;

};

#endif // SECONDLEVELSCENE_H
