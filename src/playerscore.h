#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <iostream>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QFont>
#include <QString>

class PlayerScore: public QGraphicsTextItem
{
     Q_OBJECT
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
    void decrease_health_spacecraft();

};

#endif // PLAYERSCORE_H
