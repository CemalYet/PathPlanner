#include "ViewText.h"
#include <QBrush>
#include <QGraphicsScene>
#include <qstringbuilder.h>

QGraphicsScene *ViewText::getScene() const
{
    return scene;
}


ViewText::ViewText(int rowsize, int colsize):rows{rowsize},cols{colsize}
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






void ViewText::setTextTileView(int Xpos, int Ypos, float value, TileType type)
{

     auto tileView=std::make_shared<StringTextView>(Xpos,Ypos,value,type);
     tileViewVectors.push_back(tileView);

}


QString ViewText::buildView()
{
    QString tileBuilded="";

    for(int i=0;i<rows;i++){

       appendBoundaryLine(tileBuilded);


        tileBuilded=tileBuilded%"+\n";
        int tileRowBeginIndex = i * cols ;
        for(int j=0;j<cols;j++){
             auto tileView = tileViewVectors.at(tileRowBeginIndex+j);
            tileBuilded=tileBuilded%(tileView->getTileDrawing());
        }
        tileBuilded=tileBuilded%"+\n";
       if(i==rows-1){
           appendBoundaryLine(tileBuilded);
       }

    }

    return tileBuilded;
}

void ViewText::appendBoundaryLine(QString &tileBuilded){
    QString upperdimension="+----";
    for (int j=0;j<cols;j++){
    tileBuilded=tileBuilded%upperdimension;
    }
}

void ViewText::selectNearestTile()
{

}

