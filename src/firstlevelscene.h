#ifndef FIRSTLEVELSCENE_H
#define FIRSTLEVELSCENE_H

#include "player.h"

#include <iostream>
#include <vector>
#include <string>
#include <QGraphicsScene>
#include <QGraphicsView>

class FirstLevelScene
{
public:
    FirstLevelScene();
    ~FirstLevelScene();
    void setGraphicsScene(QGraphicsView *g);
    void movePlayer();
    void noMovePlayer();
    void modifyPositionDir(int pos);
    int getXPlayerPos();
    int getYPlayerPos();
private:
    QGraphicsView *g;
    QGraphicsScene *s;
    Player *p;
    std::vector<std::string> playerSprites = {":/spritres/characters/Rick.png", ":/spritres/characters/Morty.png"};
};

#endif // FIRSTLEVELSCENE_H
