#ifndef XENEMYMODEL_H
#define XENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "gameModel.h"

class  XenemyModel
{
public:
    std::shared_ptr<enemyModel> xEnemy;

    void createEnemy();
};

#endif // XENEMYMODEL_H
