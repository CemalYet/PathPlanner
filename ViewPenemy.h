#ifndef VIEWPENEMY_H
#define VIEWPENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "PenemyModel.h"

class  ViewPenemy
{
public:
    std::shared_ptr<enemyModel> pEnemy;
    void selectNearestEnemy();

};

#endif // VIEWPENEMY_H
