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

class  ViewProtagonist : public QGraphicsPixmapItem
{
public:
    ViewProtagonist(QGraphicsItem * parent=0);

    std::shared_ptr<protagonistModel> protagonist;
    void keyPressEvent(QKeyEvent * event) override;
    void selectNearestEnemy();
};

#endif // VIEWPROTAGONIST_H

