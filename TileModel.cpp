#include "TileModel.h"
#include<math.h>


bool TileModel::isObstacle()
{
    if(tile->getValue()==std::numeric_limits<float>::infinity()){
    //if (std::isinf(tile->getValue())){*/////   //:/
        return true;
    }
    return false;

}

void TileModel::setInfinity()
{
    tile->setValue(std::numeric_limits<float>::infinity());
}

