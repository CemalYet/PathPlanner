#include "protagonistModel.h"


//Constructor
protagonistModel::protagonistModel()
{}

//Methods
void protagonistModel::moveRight()
{  //if in range and not infinity and have enough energy
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
    //call pathfinder when is done
}

void protagonistModel::decreaseHealth(float value)
{  if(protagonist->getHealth()-value >0){
        protagonist->setHealth(protagonist->getHealth() - value);
    }else{
        protagonist->setHealth(0.0);
    }


}

void protagonistModel::decreaseEnergy(float value)
{   if(protagonist->getEnergy()-value >0){
        protagonist->setEnergy(protagonist->getEnergy() - value);
    }else{
        protagonist->setEnergy(0.0);
    }

}

void protagonistModel::increaseHealth(float value)
{   if(protagonist->getHealth()+value<100){
        protagonist->setHealth(protagonist->getHealth() + value);
    }else{
        protagonist->setHealth(100);
    }

}


