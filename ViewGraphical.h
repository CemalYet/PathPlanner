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
public:
    ViewGraphical(QWidget * parent=0);  //constructor

    QGraphicsScene * scene;
    ViewProtagonist * viewProtagonist;
    ViewHealth * viewHealth;
    ViewPenemy * viewPEnemy;


    //std::shared_ptr<ViewText> textView;
    std::shared_ptr<ViewGraphical> graphicsView;
    bool isGraphical;
    //std::shared_ptr<ControllerViewSwitch> controller;

    void initWorld();
    void gameResult();
    void updateOverallView();

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
