#ifndef VIEWXENEMY_H
#define VIEWXENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "PenemyModel.h"

class  ViewXenemy
{
public:
    std::shared_ptr<enemyModel> xEnemy;
    void selectNearestEnemy();

};

#endif // VIEWXENEMY_H
