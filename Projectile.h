#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "world.h"
#include "world_global.h"
#include "ViewPenemy.h"


class Projectile: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile();
    Projectile(int x);
    Projectile(int x, int y);
    Projectile(int x, int y, int z);
    //ViewPenemy * viewPEnemy_defeated;


public slots:
    void move_right();
    void move_up();
    void move_down();
    void move_left();

private:
    const std::shared_ptr<PEnemy> &getPoison() const{return getPoison();};
};

#endif // PROJECTILE_H
