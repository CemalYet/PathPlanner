#ifndef HEALTHPACKMODEL_H
#define HEALTHPACKMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>

class  HealthPackModel
{
public:
    std::shared_ptr<HealthPackModel> healthPack;
    void method();

};

#endif // HEALTHPACKMODEL_H
