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
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "world.h"
#include "world_global.h"
#include "TileModel.h"

class  ViewProtagonist : public QGraphicsPixmapItem
{
public:
    ViewProtagonist(QGraphicsItem * parent=0);

    std::shared_ptr<protagonistModel> protagonist;
    void keyPressEvent(QKeyEvent * event) override;
    void selectNearestEnemy();

private:
    std::shared_ptr<TileModel> tile;
};

#endif // VIEWPROTAGONIST_H

