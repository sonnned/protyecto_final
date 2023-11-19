#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QPixmap>

class background : public QPixmap
{
private:
    int x;
    int y;


public:
    background();
};

#endif // BACKGROUND_H
