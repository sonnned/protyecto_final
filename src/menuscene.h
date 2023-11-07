#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MenuScene
{
public:
    MenuScene();
    ~MenuScene();
    void set_graphicsview(QGraphicsView *g);
private:
    QGraphicsView *g;
    QGraphicsScene *s;
};

#endif // MENUSCENE_H
