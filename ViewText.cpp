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

       appendBoundaryLine(tileBuilded,cols);


        tileBuilded=tileBuilded%"+\n";
        int tileRowBeginIndex = i * cols ;
        for(int j=0;j<cols;j++){
             auto tileView = tileViewVectors.at(tileRowBeginIndex+j);
            tileBuilded=tileBuilded%(tileView->drawTextTile());
        }
        tileBuilded=tileBuilded%"+\n";
       if(i==rows-1){
           appendBoundaryLine(tileBuilded,cols);
       }

    }

    return tileBuilded;
}

QString ViewText::buildPartialView(const int &xPos, const int &yPos)
{
    QString tileBuilded="";
    int numberdisplay=5;
    int startRow=yPos>numberdisplay?yPos-numberdisplay:0;
    int endRow=yPos+numberdisplay<rows?yPos+numberdisplay:rows;
    int startCol=xPos>numberdisplay?xPos-numberdisplay:0;
    int endCol=xPos+numberdisplay<cols?xPos+numberdisplay:cols;

    std::cout<<"["<<startCol<<","<<startRow<<"]"<<",["<<endCol<<","<<endRow<<"]"<<std::endl;

    for(int i=startRow;i<endRow;i++){
        appendBoundaryLine(tileBuilded,endCol-startCol);
        tileBuilded=tileBuilded%"+\n";

       int tileRowBeginIndex = i * cols ;
       for(int j=startCol;j<endCol;j++){
           auto tileView = tileViewVectors.at(tileRowBeginIndex+j);
          tileBuilded=tileBuilded%(tileView->drawTextTile());

       }
       tileBuilded=tileBuilded%"+\n";
       if(i==endRow-1){
           appendBoundaryLine(tileBuilded,endCol-startCol);
       }

    }
    return tileBuilded;
}

void ViewText::updateProgonistTileView(const int &xPos, const int &yPos)
{

    auto newProtagonistView=tileViewVectors.at(xPos+yPos*cols);

    //newProtagonistView->setTileType(TileType::Protagonist);
   // if(newProtagonistView->getTileType() ==(TileType::NormalTile) ){//added

    switch(newProtagonistView->getTileType()){
    case TileType::NormalTile :
        newProtagonistView->setTileType(TileType::Protagonist);
    break;
    case TileType::Enemy :
        std::cout<<"enemy ahead"<<std::endl;
    break;
    case TileType::PEnemy :
        std::cout<<"penemy ahead"<<std::endl;

    case TileType::XEnemy :
        std::cout <<"xenemy ahead"<<std::endl;
    case TileType::HealthPack:
        std::cout <<"grab health pack"<<std::endl;

     }
}
void ViewText::clearProtagonistTileView(const int &xPos, const int &yPos)
{
    auto currentProtagonistView=tileViewVectors.at(xPos+yPos*cols);
    currentProtagonistView->setTileType(TileType::NormalTile);
}

void ViewText::printTileViewVectors()
{
    for(auto &v:tileViewVectors){
    std::cout<<"["<<v->getStringXpos()<<","<<v->getStringYpos()<<"], " <<getStringForEnum(v->getTileType())<<std::endl;
    }
}

void ViewText::appendBoundaryLine(QString &tileBuilded,const int &number){
    QString upperdimension="+----";
    for (int j=0;j<number;j++){
    tileBuilded=tileBuilded%upperdimension;
    }
}

void ViewText::selectNearestTile()
{

}

