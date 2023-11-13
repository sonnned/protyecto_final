#include "firstlevelscene.h"

FirstLevelScene::FirstLevelScene()
{
    //player = new Player(100, 10, 10, 10, 0, 0, 2, playerSprites[0], 1000);
}

FirstLevelScene::~FirstLevelScene()
{
    delete player;
}
