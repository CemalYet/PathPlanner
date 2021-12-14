#include "ViewGraphical.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>


ViewGraphical::ViewGraphical(int rowsize, int colsize):rows{rowsize},cols{colsize}
{
    scene = new QGraphicsScene();
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

QGraphicsScene *ViewGraphical::getScene() const
{

    return scene;
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
