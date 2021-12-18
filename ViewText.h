#ifndef VIEWTEXT_H
#define VIEWTEXT_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "ViewGraphical.h"
#include "controllerViewSwitch.h"
#include "QGraphicsRectItem"
#include "tileType.h"
#include "stringtextview.h"

//class ViewGraphical;
//class ControllerViewSwitch;


class  ViewText :public QObject
{
Q_OBJECT;
private:

    QGraphicsScene* scene;
    int rows;
    int cols;
    std::string tiletype;
    std::vector<std::shared_ptr<StringTextView>>tileViewVectors;
    void appendBoundaryLine(QString &tileBuilded,const int &number);
public:

    ViewText(int rows,int col);
    void initWorld();
    void gameResult();
    void updateOverallView();
    void selectNearestTile();
    void setTextTileView(int Xpos,int Ypos, float value,TileType type);
    QGraphicsScene *getScene() const;
    QString buildView();
    QString buildPartialView(const int &xPos, const int &yPos);
    void updateProgonistTileView(const int &xPos,const int &yPos);
    void updateDeadEnemyView(const int &xPos,const int &yPos);
    void updateTakenHealthPackView(const int &xPos,const int &yPos);
    void clearProtagonistTileView(const int &prevXPos, const int &prevYPos);
    void printTileViewVectors();//for testing purpose, delete after once the game is working


};

#endif // VIEWTEXT_H
