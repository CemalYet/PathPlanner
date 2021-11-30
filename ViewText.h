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

//class ViewGraphical;
//class ControllerViewSwitch;


class  ViewText
{
private:
    QString view;
    QGraphicsScene* scene;

    std::vector<std::shared_ptr<ViewTileText>>tileViewVectors;
public:

   // std::shared_ptr<ViewText> textView;
   // std::shared_ptr<ViewGraphical> graphicsView;
   // bool isText;
   // std::shared_ptr<ControllerViewSwitch> controller;

    ViewText();
    void initWorld();
    void gameResult();
    void updateOverallView();
    void selectNearestTile();
    void setTextTileView(int Xpos,int Ypos, float value);
    QString getTextView() const;
    QGraphicsScene *getScene() const;



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
