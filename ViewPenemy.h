#ifndef VIEWPENEMY_H
#define VIEWPENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "PenemyModel.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include "gameModel.h"
//#include "ViewProtagonist.h"

class  ViewPenemy : public QGraphicsPixmapItem
{
public:
    std::shared_ptr<PenemyModel> pEnemy;
    void selectNearestEnemy();

};

#endif // VIEWPENEMY_H
