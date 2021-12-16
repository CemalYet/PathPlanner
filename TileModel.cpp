#include "TileModel.h"
#include<math.h>


bool TileModel::isObstacle()
{
    if(tile->getValue()==std::numeric_limits<float>::infinity()) {
        qDebug() << "tile value is " << tile->getValue()<<"["<< tile->getXPos() << "," <<tile->getYPos()<<"]";
        return true;
    }
    return false;

}

void TileModel::setInfinity()
{
    tile->setValue(std::numeric_limits<float>::infinity());
}

