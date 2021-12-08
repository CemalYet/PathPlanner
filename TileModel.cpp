#include "TileModel.h"


bool TileModel::isObstacle()
{
    if(tile->getValue()==std::numeric_limits<float>::infinity()) {
        qDebug() << "tile value is " << tile->getValue()<<"["<< tile->getXPos() << "," <<tile->getYPos()<<"]";
        return true;
    }
    return false;

}

