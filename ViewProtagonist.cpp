#include "ViewProtagonist.h"
#include "PenemyModel.h"
#include "Projectile.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void ViewProtagonist::selectNearestEnemy()
{

}

ViewProtagonist::ViewProtagonist(QGraphicsItem *parent)
{

}

void ViewProtagonist::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left){
        if (pos().x() > 0)  {  //make sure that protagonist doesn't pass the frame while moving left
        //if(tile->isObstacle() == false) {
        setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800){  //its x-cordination + its width shouldn't be bigger than the width of the screen
        //if(tile->isObstacle() == false) {
        setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0){
        //if(tile->isObstacle() == false){
        setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 600){
        //if(tile->isObstacle() == false) {
        setPos(x(),y()+10);
        }
    }
    else if (event->key() == Qt::Key_Space){
            // create a bullet
            Projectile * projectile = new Projectile();
            projectile->setPos(x(),y());
            scene()->addItem(projectile);
        }
}
