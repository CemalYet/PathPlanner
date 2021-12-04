#include "Projectile.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>

Projectile::Projectile(){
    // drew the rect
    setRect(0,0,15,15);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Projectile::move(){
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(ViewPenemy)){
                // remove them both
                //scene()->removeItem(colliding_items[i]);

                //add another png to show the defeated enemy
                viewPEnemy_defeated = new ViewPenemy();
                viewPEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
                //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
                //viewPEnemy->setPos(viewPEnemy->pEnemy->getPEnemy()->getXPos() , viewPEnemy->pEnemy->getPEnemy()->getYPos());
                viewPEnemy_defeated->setPos(250, 300);
                scene()->addItem(viewPEnemy_defeated);


                scene()->removeItem(this);
                // delete them both
                delete colliding_items[i];
                //delete this;




                //draw the poison after defeating an enemy

                //auto poison_area = scene()->addRect(-100,-100,50,50);
                return;
            }
        }
    // move bullet up
    setPos(x(),y()-10);
}
