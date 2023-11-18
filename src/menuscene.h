#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class MenuScene: public QObject
{
public:
    MenuScene();
    ~MenuScene();
    void setGraphicsScene(QGraphicsView *g);
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    QGraphicsTextItem *menuTitle;
    QPushButton *continueBtn;
    QGraphicsProxyWidget *continueBtnProxy;
    QPushButton *backBtn;
    QGraphicsProxyWidget *backBtnProxy;
    void setMenuItems();
    /*
private slots:
    void continueBtnClicked();
    void backBtnClicked();
signals:
    void continueClicked();
    void backClicked();
*/
};

#endif // MENUSCENE_H
