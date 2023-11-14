#include "secondlevelscene.h"

SecondLevelScene::SecondLevelScene()
{
    background_2 = new QImage(":/spritres/backgrounds/fondo_espacio.jpg");
}

SecondLevelScene::~SecondLevelScene()
{
    delete background_2;
}
