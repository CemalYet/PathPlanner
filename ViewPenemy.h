#ifndef VIEWPENEMY_H
#define VIEWPENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "PenemyModel.h"
#include <QGraphicsRectItem>

class  ViewPenemy : public QGraphicsRectItem
{
public:
    std::shared_ptr<PenemyModel> pEnemy;
    void selectNearestEnemy();

};

#endif // VIEWPENEMY_H
