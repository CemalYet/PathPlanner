#include "ViewProtagonist.h"
//#include "PenemyModel.h"
//#include "Projectile.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>

ViewProtagonist::ViewProtagonist(QGraphicsItem *parent, const int &x, const int &y)
{
    setPixmap(QPixmap(":/images/scorpion_4.png"));
    setPos(x, y);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

//ViewProtagonist::ViewProtagonist()
//{

//}


void ViewProtagonist::selectNearestEnemy()
{

}

void ViewProtagonist::addAll(std::vector<std::unique_ptr<Tile> > &tiles, std::vector<std::unique_ptr<Tile> > &data)
{
//    for(unsigned int i=0;i<tiles.size();i++){
//            addTile(move(tiles[i]),data);
//        }

}

void ViewProtagonist::moveRight(const int protagonistXPos, const int protagonistYPos, std::shared_ptr<GameModel> g_model)
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
                viewPEnemy_defeated->setPos(protagonistXPos, 0);
                scene()->addItem(viewPEnemy_defeated);
                // delete them both
                delete colliding_items[i];
                //delete this;

                //draw the poison after defeating an enemy

                //dvrease health when hitting an enemy
                //g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
                g_model->getProtagonist()->decreaseHealth(10);
                //auto poison_area = scene()->addRect(-100,-100,50,50);
                qDebug() << "ViewProtagonist x_pos is " << g_model->getProtagonist()->getProtagonist()->getXPos();
                qDebug() << "ViewProtagonist y_pos is " << g_model->getProtagonist()->getProtagonist()->getYPos();
                return;
            }

            if (typeid(*(colliding_items[i])) == typeid(XenemyModel)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
                // remove them both
                scene()->removeItem(colliding_items[i]);

                //add another png to show the defeated enemy
                viewXEnemy_defeated = new ViewXenemy(0,7,8);
                viewXEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
                //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
                viewXEnemy_defeated->setPos(protagonistXPos, 0);
                scene()->addItem(viewXEnemy_defeated);
                // delete them both
                delete colliding_items[i];
                //delete this;

                //draw the poison after defeating an enemy

                //dvrease health when hitting an enemy
                g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
                //auto poison_area = scene()->addRect(-100,-100,50,50);
                return;
            }

            if (typeid(*(colliding_items[i])) == typeid(ViewHealthPack)){
                scene()->removeItem(colliding_items[i]);
                g_model->getProtagonist()->increaseHealth(10);
            }
        }
    // move protagonist to the right
    setPos(x()+1,y());
}

void ViewProtagonist::moveLeft(const int protagonistXPos, const int protagonistYPos, std::shared_ptr<GameModel> g_model)
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
            viewPEnemy_defeated->setPos(protagonistXPos, 0);
            scene()->addItem(viewPEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //decrease health
            //g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
            g_model->getProtagonist()->decreaseHealth(10);
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

        if (typeid(*(colliding_items[i])) == typeid(XenemyModel)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
            // remove them both
            scene()->removeItem(colliding_items[i]);

            //add another png to show the defeated enemy
            viewXEnemy_defeated = new ViewXenemy(0,7,8);
            viewXEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
            //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
            viewXEnemy_defeated->setPos(protagonistXPos, 0);
            scene()->addItem(viewXEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //draw the poison after defeating an enemy

            //dvrease health when hitting an enemy
            g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(ViewHealthPack)){
            scene()->removeItem(colliding_items[i]);
            g_model->getProtagonist()->increaseHealth(10);
        }
    }
    setPos(x()-1,y());
}

void ViewProtagonist::moveUp(const int protagonistXPos, const int protagonistYPos, std::shared_ptr<GameModel> g_model)
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
            viewPEnemy_defeated->setPos(protagonistXPos, 0);
            scene()->addItem(viewPEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //decrease health
            g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
            g_model->getProtagonist()->decreaseHealth(10);

            //draw the poison after defeating an enemy

            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(XenemyModel)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
            // remove them both
            scene()->removeItem(colliding_items[i]);

            //add another png to show the defeated enemy
            viewXEnemy_defeated = new ViewXenemy(0,7,8);
            viewXEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
            //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
            viewXEnemy_defeated->setPos(protagonistXPos, 0);
            scene()->addItem(viewXEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //draw the poison after defeating an enemy

            //dvrease health when hitting an enemy
            g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(ViewHealthPack)){
            scene()->removeItem(colliding_items[i]);
            g_model->getProtagonist()->increaseHealth(10);
        }
    }
    setPos(x(),y()-1);
}

void ViewProtagonist::moveDown(const int protagonistXPos, const int protagonistYPos, std::shared_ptr<GameModel> g_model)
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
            viewPEnemy_defeated->setPos(protagonistXPos, 0);
            scene()->addItem(viewPEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //decrease health
            //g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
            g_model->getProtagonist()->decreaseHealth(10);

            //draw the poison after defeating an enemy

            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(XenemyModel)){    //check if it's a PEnemy, i should add for xenemy and enemy as well
            // remove them both
            scene()->removeItem(colliding_items[i]);

            //add another png to show the defeated enemy
            viewXEnemy_defeated = new ViewXenemy(0,7,8);
            viewXEnemy_defeated->setPixmap(QPixmap(":/images/dead.png"));
            //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
            viewXEnemy_defeated->setPos(protagonistXPos, 0);
            scene()->addItem(viewXEnemy_defeated);
            // delete them both
            delete colliding_items[i];
            //delete this;

            //draw the poison after defeating an enemy

            //dvrease health when hitting an enemy
            g_model->getProtagonist()->decreaseHealth(g_model->getTileAtAPos(protagonistXPos, protagonistYPos)->getTile()->getValue());
            //auto poison_area = scene()->addRect(-100,-100,50,50);
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(ViewHealthPack)){
            scene()->removeItem(colliding_items[i]);
            g_model->getProtagonist()->increaseHealth(10);
        }
    }
    setPos(x(),y()+1);
    //qDebug() << "the x value in ViewProtagonist: " << x() << "the y value in ViewProtagonist:" << y();
}

void ViewProtagonist::setPosition(int x, int y)
{
    setPos(x,y);
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
