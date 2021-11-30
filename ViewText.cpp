#include "ViewText.h"
#include <QBrush>
#include <QGraphicsScene>
#include <qstringbuilder.h>

QGraphicsScene *ViewText::getScene() const
{
    return scene;
}

ViewText::ViewText()
{
   scene = new QGraphicsScene();
}

void ViewText::initWorld()
{

}

void ViewText::gameResult()
{

}

void ViewText::updateOverallView()
{

}

void ViewText::startNewGame()
{

}

void ViewText::startAutoPlay()
{

}

void ViewText::moveLeft()
{

}

void ViewText::moveRight()
{

}

void ViewText::moveUp()
{

}

void ViewText::moveDown()
{

}

void ViewText::isEnemyDefeated()
{

}






void ViewText::setTextTileView(int Xpos, int Ypos, float value)
{
     tileView=std::make_shared<ViewTile>();
     view =tileView->viewTileText(Xpos,Ypos,value);

}

QString ViewText::ViewText::getTextView() const
{
    return view;
}

void ViewText::selectNearestTile()
{

}

