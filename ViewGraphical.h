#ifndef VIEWGRAPHICAL_H
#define VIEWGRAPHICAL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include <QGraphicsView>
#include "ViewProtagonist.h"
#include "ViewHealth.h"
#include "ViewPenemy.h"

//class ViewText;
//class ControllerViewSwitch;

class  ViewGraphical: public QGraphicsView
{
private:
    QGraphicsScene * scene;
    int rows;
    int cols;
    ViewProtagonist * viewProtagonist;
    ViewPenemy * viewPenemy;

public:
    ViewGraphical(int rowsize, int colsize);  //constructor

    //std::shared_ptr<ViewText> textView;
    std::shared_ptr<ViewGraphical> graphicsView;
    bool isGraphical;
    //std::shared_ptr<ControllerViewSwitch> controller;

    void initWorld();
    void gameResult();
    void updateOverallView();
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

#endif // VIEWGRAPHICAL_H
