#ifndef VIEWPROTAGONIST_H
#define VIEWPROTAGONIST_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "protagonistModel.h"

class  ViewProtagonist
{
public:
    std::shared_ptr<protagonistModel> protagonist;

    void selectNearestEnemy();
};

#endif // VIEWPROTAGONIST_H
