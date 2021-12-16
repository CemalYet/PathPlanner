#ifndef VIEWXENEMY_H
#define VIEWXENEMY_H
#include<string>
#include <iostream>
#include <vector>
#include <QTimer>
#include <memory>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include "XenemyModel.h"

class ViewXenemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ViewXenemy(QGraphicsItem *parent = 0, int xPosition =0, int yPosition=0);  //create xenemy logic
    double distanceTO(QGraphicsItem * item);
    void fire();

    void setXPosition(int newXPosition);
    void setYPosition(int newYPosition);

    int getXPosition() const;
    int getYPosition() const;

public slots:
    void aquire_target();

private:
    std::shared_ptr<XenemyModel> xenemy;
    //std::vector<std::shared_ptr<XenemyModel>> xEnemies;
    int xPosition;
    int yPosition;
    QGraphicsPolygonItem * attackBoundry;
    QPointF attack_dest;
    bool hasTarget;
};

#endif // VIEWXENEMY_H
