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
#include "gameModel.h"
#include "world_global.h"
#include "PenemyModel.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "Projectile.h"
#include "ViewProtagonist.h"


class XenemyModel : public QObject, public PenemyModel, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    XenemyModel(QGraphicsItem * parent=0);   //create xenemy logic
    double distanceTO(QGraphicsItem * item);
    const std::shared_ptr<PEnemy> &getPEnemy() const{return xenemy;};
    void setPEnemy(const std::shared_ptr<PEnemy> &newXEnemy){xenemy = newXEnemy;};
    void fire();

public slots:
    void aquire_target();

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
