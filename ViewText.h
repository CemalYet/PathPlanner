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

class ViewGraphical;
class ControllerViewSwitch;

class  ViewText
{
public:

    std::shared_ptr<ViewText> textView;
    std::shared_ptr<ViewGraphical> graphicsView;
    bool isText;
    std::shared_ptr<ControllerViewSwitch> controller;

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

#endif // VIEWTEXT_H
