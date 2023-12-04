#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <iostream>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QFont>
#include <QString>

class PlayerScore: public QGraphicsTextItem
{
public:
    PlayerScore(QString text, int limit, int beg, int x, int y, int level);
private:
    int limit;
    QString text;
    int beg;
    int initialBeg;
public slots:
    void increaseCurrentDeadEnemies();
    void decreaseCurrentPlayerLife();
    void changeCurrentBullets(int bullets);
    void decrease_healt_spacecraft();
};

#endif // PLAYERSCORE_H
