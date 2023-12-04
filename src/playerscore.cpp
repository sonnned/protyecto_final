#include "playerscore.h"

PlayerScore::PlayerScore(QString text, int limit, int beg, int x, int y, int level)
{
    this->beg = beg;
    initialBeg = beg;
    this->text = text;
    this->limit = limit;
    QFontDatabase::addApplicationFont(":/fonts/m5x7.ttf");
    QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
    setPlainText(scoreText);
    if (level == 1) setDefaultTextColor(Qt::black);
    else setDefaultTextColor(Qt::white);
    setFont(QFont("m5x7", 20));
    setPos(x, y);
}

void PlayerScore::increaseCurrentDeadEnemies()
{
    if (initialBeg == 0) {
        beg++;
        QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
        setPlainText(scoreText);
    }
}

void PlayerScore::decreaseCurrentPlayerLife()
{
    if (initialBeg > 0) {
        beg -= 5;
        QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
        setPlainText(scoreText);
    }
}

void PlayerScore::changeCurrentBullets(int bullets)
{
    if (initialBeg == 4) {
        beg = bullets;
        QString scoreText = text + QString::number(beg) + QString("/") + QString::number(limit);
        setPlainText(scoreText);
    }
}

void PlayerScore::decrease_healt_spacecraft()
{

}
