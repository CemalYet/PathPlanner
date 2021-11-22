#include "TileModel.h"


bool TileModel::isObstacle()
{
    if(tile->getValue()==std::numeric_limits<float>::infinity()) {
        return true;
    }
    return false;

}

