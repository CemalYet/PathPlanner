#include "protagonistModel.h"


//Constructor
protagonistModel::protagonistModel()
{}

//Methods
void protagonistModel::moveRight()
{   //if in range and not infinity and have enough energy and health
   protagonist->setXPos(protagonist->getXPos()+1);
}

void protagonistModel::moveLeft()
{   //if in range and not infinity and have enough energy
    protagonist->setXPos(protagonist->getXPos()-1);
}

void protagonistModel::moveUp()
{  //if in range and not infinity and have enough energy
    protagonist->setYPos(protagonist->getYPos()+1);
}

void protagonistModel::moveDown()
{   //if in range and not infinity and have enough energy
    protagonist->setYPos(protagonist->getYPos()-1);
}

void protagonistModel::goTo(int x, int y)
{
    //implement when pathfinder is done
}

void protagonistModel::decreaseHealth(float value)
{  //Do not alllow to decrease under zero
   protagonist->setHealth(protagonist->getHealth() - value);
}

void protagonistModel::decreaseEnergy(float value)
{   //Do not alllow to decrease under zero
    protagonist->setEnergy(protagonist->getEnergy() - value);
}

void protagonistModel::increaseHealth(float value)
{   //Do not alllow to increase above 100
    protagonist->setHealth(protagonist->getHealth() + value);
}


