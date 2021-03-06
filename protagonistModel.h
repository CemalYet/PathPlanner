#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "world.h"
#include "HealthPackModel.h"
#include <QGraphicsPixmapItem>

const float maxEH {100.0F};

class  protagonistModel
{

public:
    protagonistModel();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void goTo(int x,   int y);
    void decreaseHealth(float value);
    void decreaseEnergy(float value);
    void increaseHealth(float value);
    void increaseEnergy();
    void killEnemy(const float &tileEnergy,const float &enemyPower,std::shared_ptr<Enemy> &nearestEnemy);
    void grabHealthPack(const float &tileEnergy,std::shared_ptr<HealthPackModel> &nearestHealthPack);
    std::shared_ptr<Protagonist> getProtagonist() const{return protagonist;};
    void setProtagonist(std::unique_ptr<Protagonist> &value){protagonist = std::move(value);};

private:
    std::shared_ptr<Protagonist> protagonist;


};

#endif // PROTAGONISTMODEL_H
