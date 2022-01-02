#include "protagonistModel.h"
#include "HealthPackModel.h"


//Constructor
protagonistModel::protagonistModel()
{}

//Methods
void protagonistModel::moveRight()
{
   protagonist->setXPos(protagonist->getXPos()+1);
}

void protagonistModel::moveLeft()
{
    protagonist->setXPos(protagonist->getXPos()-1);
}

void protagonistModel::moveUp()
{
    protagonist->setYPos(protagonist->getYPos()-1);//in text view(string builder) it is only possible to go to next line and not possible to go a line back
}

void protagonistModel::moveDown()
{
    protagonist->setYPos(protagonist->getYPos()+1);
}

void protagonistModel::goTo(int x, int y)
{
    protagonist->setXPos(x);
    protagonist->setYPos(y);
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
{   if(protagonist->getHealth()+value<maxEH){
        protagonist->setHealth(protagonist->getHealth() + value);
    }else{
        protagonist->setHealth(maxEH);
    }


}

void protagonistModel::increaseEnergy()
{
    protagonist->setEnergy(maxEH);
}

void protagonistModel::killEnemy(const float &tileEnergy,const float &enemyPower,std::shared_ptr<Enemy> &nearestEnemy){
    decreaseEnergy(tileEnergy);
     std::cout<<"Before killing enemy Protagonist health : "<<protagonist->getHealth()<<", energy : "<<protagonist->getEnergy()<<std::endl;
    decreaseHealth(enemyPower);
    goTo(nearestEnemy->getXPos(),nearestEnemy->getYPos());
    increaseEnergy();
    nearestEnemy->setDefeated(1);
}
void protagonistModel::grabHealthPack(const float &tileEnergy,std::shared_ptr<HealthPackModel> &nearestHealthPack){
    decreaseEnergy(tileEnergy);
    increaseHealth(nearestHealthPack->getHealthPack()->getValue());
    goTo(nearestHealthPack->getHealthPack()->getXPos(),nearestHealthPack->getHealthPack()->getYPos());
    nearestHealthPack->setIsPacked(true);
}



