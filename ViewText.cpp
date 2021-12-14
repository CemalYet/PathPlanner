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

   // std::cout<<"["<<startCol<<","<<startRow<<"]"<<",["<<endCol<<","<<endRow<<"]"<<std::endl;

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
    if(newProtagonistView->getTileType()==TileType::NormalTile){
        newProtagonistView->setTileType(TileType::Protagonist);
    }
}

void ViewText::updateDeadEnemyView(const int &xPos, const int &yPos)
{
    auto blockedEnemyView=tileViewVectors.at(xPos+yPos*cols);
    blockedEnemyView->setTileType(TileType::Blocked);
}

void ViewText::updateTakenHealthPackView(const int &xPos, const int &yPos)
{
    auto takenHealthView=tileViewVectors.at(xPos+yPos*cols);
    takenHealthView->setTileType(TileType::TakenHealthpack);
}


void ViewText::clearProtagonistTileView(const int &xPos, const int &yPos)
{
    auto currentProtagonistView=tileViewVectors.at(xPos+yPos*cols);
    if(currentProtagonistView->getTileType()==TileType::Protagonist){
        //std::cout<<"protagonist clear"<<xPos<<","<<yPos<<std::endl;
        currentProtagonistView->setTileType(TileType::NormalTile);
    }
   /* else if(isEnemy(currentProtagonistView->getTileType()) ){
        //Progonist has attacked the enemy tile
        currentProtagonistView->setTileType(TileType::Blocked);
    }*/


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



