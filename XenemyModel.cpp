#include "XenemyModel.h"

//class XEnemy
XEnemy::XEnemy(int xPosition, int yPosition, float strength): Enemy(xPosition, yPosition, strength)
{
  srand(time(nullptr));
}

bool XEnemy::status()
{
  if (XEnemy::cute)
    {
        setEnergyBar(50.0);
    }
  if (XEnemy::Mad){
        setEnergyBar(100.0);
  }
  if (XEnemy::furious){
        setEnergyBar(150.0);
  }
  if (XEnemy::dead){
        setEnergyBar(200.0);
  }
  return false;
}

float XEnemy::getShapeType() const
{

}

void XEnemy::setShapeType(float value)
{

}

float XEnemy::setEnergyBar(float value)
{
    return energyBar;
}


//void XenemyModel::setXEnemy(const std::shared_ptr<XEnemy> &newXEnemy, std::unique_ptr<GameModel> &gameModel){
//    auto actual_enemies=gameModel->getEnemies();
//    auto actual_penemies= gameModel->getPEnemies();
//    auto xenemy_model = std::make_shared<XenemyModel>();

//    for (int i=0; i<=30; i++){      //this loop to make sure to iterate within (30,30)
//        int x=0; int y=0;
//        for(auto &e:actual_enemies){
//            for(auto &p_enemy:actual_penemies){
//                if ( (x != e->getEnemy()->getXPos()) && (y != e->getEnemy()->getXPos()) ){
//                    if ( (x != p_enemy->getPEnemy()->getXPos()) && (y != p_enemy->getPEnemy()->getXPos()) ){
//                        xenemy_model->setXPos(x);
//                        xenemy_model->setYPos(y);
//                        xEnemies.push_back(xenemy_model);

//                    }
//                }
//            }

//        }
//        x++;
//        y++;
//    }
//}

void XenemyModel::setXEnemy( int x, int y){
    std::shared_ptr<XEnemy> newXEnemy;
    xPosition = x;
    yPosition = y;
    newXEnemy->setXPos(x);
    newXEnemy->setYPos(y);
}


