#include "ViewGraphical.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>


ViewGraphical::ViewGraphical(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/maze3")));

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
