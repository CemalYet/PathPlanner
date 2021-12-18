#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "world.h"
#include "world_global.h"

class Projectile: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile();

public slots:
    void move();

private:
    const std::shared_ptr<PEnemy> &getPoison() const{return getPoison();};
};

#endif // PROJECTILE_H
