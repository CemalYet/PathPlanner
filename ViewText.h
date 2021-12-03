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
#include "viewTiletext.h"
#include "tileType.h"
#include "stringtextview.h"

//class ViewGraphical;
//class ControllerViewSwitch;


class  ViewText
{
private:
   // QString view;
    //ViewTileText view;
    QGraphicsScene* scene;
    int rows;
    int cols;
    std::string tiletype;
    std::vector<std::shared_ptr<StringTextView>>tileViewVectors;
    void appendBoundaryLine(QString &tileBuilded);
public:

   // std::shared_ptr<ViewText> textView;
   // std::shared_ptr<ViewGraphical> graphicsView;
   // bool isText;
   // std::shared_ptr<ControllerViewSwitch> controller;

    ViewText(int rows,int col);
    void initWorld();
    void gameResult();
    void updateOverallView();
    void selectNearestTile();
    void setTextTileView(int Xpos,int Ypos, float value,TileType type);
   // ViewTileText getTextView() const;
    QGraphicsScene *getScene() const;
    QString buildView();



public slots:
    void startNewGame();
    void startAutoPlay();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void isEnemyDefeated();


};

#endif // VIEWTEXT_H
