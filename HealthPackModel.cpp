#include "HealthPackModel.h"

const std::shared_ptr<Tile> &HealthPackModel::getHealthPack() const
{
    return healthPack;
}

void HealthPackModel::setHealthPack(const std::shared_ptr<Tile> &newHealthPack)
{
    healthPack = newHealthPack;
}

bool HealthPackModel::getIsPacked() const
{
    return isPacked;
}

void HealthPackModel::setIsPacked(bool newIsPacked)
{
    isPacked = newIsPacked;
}


