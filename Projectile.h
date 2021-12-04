#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>
#include "world.h"
#include "world_global.h"
#include "ViewPenemy.h"
#include "ViewGraphical.h"

class Projectile: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Projectile();
    ViewPenemy * viewPEnemy_defeated;


public slots:
    void move();

private:
    const std::shared_ptr<PEnemy> &getPoison() const{return getPoison();};
};

#endif // PROJECTILE_H
