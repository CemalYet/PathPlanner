#ifndef HEALTHPACKMODEL_H
#define HEALTHPACKMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include"world.h"

class  HealthPackModel
{
public:
    std::shared_ptr<Tile> healthPack;


    const std::shared_ptr<Tile> &getHealthPack() const;
    void setHealthPack(const std::shared_ptr<Tile> &newHealthPack);


};

#endif // HEALTHPACKMODEL_H
