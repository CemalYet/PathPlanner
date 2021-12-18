#include "XenemyModel.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsScene>
#include "ViewProtagonist.h"

XenemyModel::XenemyModel(QGraphicsItem *parent)
{

}


int XenemyModel::getXPosition() const
{
    return xPosition;
}

int XenemyModel::getYPosition() const
{
    return yPosition;
}

void XenemyModel::setXPosition(int newXPosition)
{
    xPosition = newXPosition;
}

void XenemyModel::setYPosition(int newYPosition)
{
    yPosition = newYPosition;
}
