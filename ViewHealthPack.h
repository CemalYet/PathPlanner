#ifndef VIEWHEALTHPACK_H
#define VIEWHEALTHPACK_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "HealthPackModel.h"
#include <QGraphicsPixmapItem>

class  ViewHealthPack : public QGraphicsPixmapItem
{
public:
    std::shared_ptr<HealthPackModel> healthPack;

    void selectNearestPack();
};

#endif // VIEWHEALTHPACK_H
