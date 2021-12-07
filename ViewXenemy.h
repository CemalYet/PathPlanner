#ifndef VIEWXENEMY_H
#define VIEWXENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "XenemyModel.h"

class  ViewXenemy : public QGraphicsPixmapItem
{
public:
    std::shared_ptr<XenemyModel> xEnemy;
    void selectNearestEnemy();

};

#endif // VIEWXENEMY_H
