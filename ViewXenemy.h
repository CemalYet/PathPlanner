#ifndef VIEWXENEMY_H
#define VIEWXENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"

class  ViewXenemy
{
public:
    std::shared_ptr<EnemyModel> xEnemy;
    void selectNearestEnemy();

};

#endif // VIEWXENEMY_H
