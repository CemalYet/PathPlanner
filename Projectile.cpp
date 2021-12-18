#include "Projectile.h"
#include <QTimer>
#include <QList>
#include <QPixmap>
#include <QGraphicsScene>
#include "ViewProtagonist.h"

Projectile::Projectile(){
    setPixmap(QPixmap(":/images/sindel_scream.png"));

    // connect
    QTimer * move_timer = new QTimer();
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));

    move_timer->start(500);
}

void Projectile::move(){
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(ViewProtagonist)){
                // remove them both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                delete colliding_items[i];
                return;
            }
        }
    // move bullet to the right
    setPos(x()+10,y());
}




