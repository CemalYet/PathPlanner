#ifndef XENEMYMODEL_H
#define XENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include <queue>
#include <vector>
#include "enemyModel.h"
#include "PenemyModel.h"
#include "world.h"
#include "world_global.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class XenemyModel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    XenemyModel(QGraphicsItem * parent=0);   //create xenemy logic
    const std::shared_ptr<PEnemy> &getXEnemy() const{return xenemy;};
    void setXEnemy(const std::shared_ptr<PEnemy> &newXEnemy){xenemy = newXEnemy;};
    void setXPosition(int newXPosition);
    void setYPosition(int newYPosition);
    int getXPosition() const;
    int getYPosition() const;


private:
    std::shared_ptr<PEnemy> xenemy;
    //std::vector<std::shared_ptr<XenemyModel>> xEnemies;
    int xPosition;
    int yPosition;
    QGraphicsPolygonItem * attackBoundry;
    QPointF attack_dest;
    bool hasTarget;
};

#endif // XENEMYMODEL_H
