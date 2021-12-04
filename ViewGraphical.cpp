#include "ViewGraphical.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>


ViewGraphical::ViewGraphical(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/maze1")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    viewProtagonist = new ViewProtagonist();
    //viewProtagonist->setRect(0,0,90,90);
    viewProtagonist->setPixmap(QPixmap(":/images/scorpion_32px.png"));
    viewProtagonist->setPos(0,0);

    viewProtagonist->setFlag(QGraphicsItem::ItemIsFocusable);
    viewProtagonist->setFocus();
    scene->addItem(viewProtagonist);

    viewHealth = new ViewHealth();
    scene->addItem(viewHealth);
    viewHealth->setPos(viewHealth->x()+90,viewHealth->y()+25);



    viewPEnemy = new ViewPenemy();
    viewPEnemy->setPixmap(QPixmap(":/images/scorpion_32px.png"));
    //std::cout<<"penemy x coordination is : "<< viewPEnemy->pEnemy->getPEnemy()->getXPos()<<std::endl;
    //viewPEnemy->setPos(viewPEnemy->pEnemy->getPEnemy()->getXPos() , viewPEnemy->pEnemy->getPEnemy()->getYPos());
    viewPEnemy->setPos(250, 300);

    scene->addItem(viewPEnemy);

    show();
}

void ViewGraphical::initWorld()
{

}

void ViewGraphical::gameResult()
{

}

void ViewGraphical::updateOverallView()
{

}

void ViewGraphical::startNewGame()
{

}

void ViewGraphical::startAutoPlay()
{

}

void ViewGraphical::moveLeft()
{

}

void ViewGraphical::moveRight()
{

}

void ViewGraphical::moveUp()
{

}

void ViewGraphical::moveDown()
{

}

void ViewGraphical::isEnemyDefeated()
{

}
