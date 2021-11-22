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

    }
  if (XEnemy::Mad){

  }
  if (XEnemy::furious){

  }
  if (XEnemy::dead){

  }
  return false;
}

float XEnemy::getShapeType() const
{

}

void XEnemy::setShapeType(float value)
{

}
