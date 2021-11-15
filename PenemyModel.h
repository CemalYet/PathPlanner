#ifndef PENEMYMODEL_H
#define PENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "gameModel.h"

class  PenemyModel
{
public:
    std::shared_ptr<enemyModel> pEnemyModel;

    void getEnemyPosition();

};

#endif // PENEMYMODEL_H
