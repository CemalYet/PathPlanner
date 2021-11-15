#ifndef VIEWENEMY_H
#define VIEWENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "protagonistModel.h"

class  ViewEnemy
{
public:
    std::shared_ptr<protagonistModel> protagonist;

    void selectNearestEnemy();

};

#endif // VIEWENEMY_H
