#ifndef CONTROLLERVIEWSWITCH_H
#define CONTROLLERVIEWSWITCH_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "ViewGraphical.h"
#include "ViewText.h"

class  ControllerViewSwitch
{
public:
    ControllerViewSwitch ();
    int HW;
    QTimer *timer;


public slots:
    void timerFunction();
    void selectView();


};


#endif // CONTROLLERVIEWSWITCH_H
