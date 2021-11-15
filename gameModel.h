#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "TileModel.h"
#include "HealthPackModel.h"
#include "PenemyModel.h"
#include "enemyModel.h"
#include "protagonistModel.h"
#include "XenemyModel.h"

class XenemyModel;


class  gameModel
{
public:
    std::shared_ptr<protagonistModel> protagonist;
    std::shared_ptr<TileModel> tile;
    std::shared_ptr<HealthPackModel> healthPack;
    std::shared_ptr<enemyModel> pEnemy;

    void method();
    //enemyModel::selectNearestEnemy();
    //TileModel::findFirstHealthPack();
    void getXenemy (std::shared_ptr<XenemyModel> xEnemy);

};


#endif // GAMEMODEL_H
