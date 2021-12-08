#include "ViewProtagonist.h"
//#include "PenemyModel.h"
//#include "Projectile.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>


void ViewProtagonist::selectNearestEnemy()
{

}

void ViewProtagonist::addAll(std::vector<std::unique_ptr<Tile> > &tiles, std::vector<std::unique_ptr<Tile> > &data)
{
//    for(unsigned int i=0;i<tiles.size();i++){
//            addTile(move(tiles[i]),data);
//        }

}

void ViewProtagonist::moveRight(const int protagonistXPos, const int protagonistYPos)
{

//    qDebug() << "I'm updating viewProtagonist to the right";
//    qDebug() << "------------------------------------------------";
    // if bullet collides with enemy, destroy both
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(ViewPenemy)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
                // remove them both
                scene()->removeItem(colliding_items[i]);

                //add another png to show the defeated enemy
                viewPEnemy_defeated = new ViewPenemy();
                viewPEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
                //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
                viewPEnemy_defeated->setPos(protagonistXPos + 30, protagonistYPos);
                scene()->addItem(viewPEnemy_defeated);
                // delete them both
                delete colliding_items[i];
                //delete this;

                //draw the poison after defeating an enemy

                //auto poison_area = scene()->addRect(-100,-100,50,50);
                return;
            }
        }
    // move protagonist to the right
    setPos(x()+1,y());
}

void ViewProtagonist::moveLeft(const int protagonistXPos, const int protagonistYPos)
{
//    qDebug() << "I'm updating viewProtagonist to the right";
//    qDebug() << "------------------------------------------------";

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(ViewPenemy)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
            // remove them both
            scene()->removeItem(colliding_items[i]);

            //add another png to show the defeated enemy
            viewPEnemy_defeated = new ViewPenemy();
            viewPEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
            //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
            viewPEnemy_defeated->setPos(protagonistXPos - 30, protagonistYPos);
            scene()->addItem(viewPEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;


            //draw the poison after defeating an enemy
//            ViewProtagonist * poisoned_protagonist = new ViewProtagonist();
//            poisoned_protagonist->protagonist;
//            protagonist->setXPos(protagonistXPos);
//            protagonist->setYPos(protagonistYPos);
//            poisoned_protagonist->setPixmap(QPixmap(":/images/Raiden.png"));
//            poisoned_protagonist->setPos(protagonistXPos, protagonistYPos);
//            scene()->addItem(poisoned_protagonist);

            //auto poison_area = scene()->addRect(-100,-100,50,50);
        }
    }
    setPos(x()-1,y());
}

void ViewProtagonist::moveUp(const int protagonistXPos, const int protagonistYPos)
{
//    qDebug() << "I'm updating viewProtagonist to the up";
//    qDebug() << "------------------------------------------------";

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(ViewPenemy)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
            // remove them both
            scene()->removeItem(colliding_items[i]);

            //add another png to show the defeated enemy
            viewPEnemy_defeated = new ViewPenemy();
            viewPEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
            //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
            viewPEnemy_defeated->setPos(protagonistXPos - 30, protagonistYPos);
            scene()->addItem(viewPEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //draw the poison after defeating an enemy

            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }
    }
    setPos(x(),y()-1);
}

void ViewProtagonist::moveDown(const int protagonistXPos, const int protagonistYPos)
{
//    qDebug() << "I'm updating viewProtagonist to the down";
//    qDebug() << "------------------------------------------------";

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(ViewPenemy)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
            // remove them both
            scene()->removeItem(colliding_items[i]);

            //add another png to show the defeated enemy
            viewPEnemy_defeated = new ViewPenemy();
            viewPEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
            //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
            viewPEnemy_defeated->setPos(protagonistXPos - 30, protagonistYPos);
            scene()->addItem(viewPEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //draw the poison after defeating an enemy

            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }
    }
    setPos(x(),y()+1);
    //qDebug() << "the x value in ViewProtagonist: " << x() << "the y value in ViewProtagonist:" << y();
}


ViewProtagonist::ViewProtagonist(QGraphicsItem *parent)
{

}

//void ViewProtagonist::keyPressEvent(QKeyEvent *event)
//{

//    if(event->key() == Qt::Key_Left){
//        if (pos().x() > 0)  {  //make sure that protagonist doesn't pass the frame while moving left
//        //if(tile->getValue() != std::numeric_limits<float>::infinity()) {
//        setPos(x()-10,y());
//        }
//    }
//    else if (event->key() == Qt::Key_Right){
//        if (pos().x() + 100 < 800){  //its x-cordination + its width shouldn't be bigger than the width of the screen
//        //if(tile->getValue() != std::numeric_limits<float>::infinity()) {
//        setPos(x()+10,y());
//        }
//    }
//    else if (event->key() == Qt::Key_Up){
//        if (pos().y() > 0){
//        //if(tile->getValue() != std::numeric_limits<float>::infinity()){
//        setPos(x(),y()-10);
//        }
//    }
//    else if (event->key() == Qt::Key_Down){
//        if (pos().y() + 100 < 600){
//        //if(tile->getValue() != std::numeric_limits<float>::infinity()){
//        setPos(x(),y()+10);
//        }
//    }
//    else if (event->key() == Qt::Key_D){
//            // create a bullet
//            Projectile * projectile = new Projectile();
//            projectile->setPos(x(),y());
//            scene()->addItem(projectile);
//        }
//    else if (event->key() == Qt::Key_Z){
//            // create a bullet
//            Projectile * projectile = new Projectile(5);
//            projectile->setPos(x(),y());
//            scene()->addItem(projectile);
//        }
//    else if (event->key() == Qt::Key_S){
//            // create a bullet
//            Projectile * projectile = new Projectile(5,6);
//            projectile->setPos(x(),y());
//            scene()->addItem(projectile);
//        }
//    else if (event->key() == Qt::Key_Q){
//            // create a bullet
//            Projectile * projectile = new Projectile(5,6,6);
//            projectile->setPos(x(),y());
//            scene()->addItem(projectile);
//        }
//}
