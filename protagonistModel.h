#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "gameModel.h"

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

//  might be
//  void attack();




    const std::shared_ptr<Protagonist> &getProtagonist() const{
        return protagonist;
    };
    void setProtagonist(const std::shared_ptr<Protagonist> &newProtagonist){
        protagonist = newProtagonist;
    };

private:
    std::shared_ptr<Protagonist> protagonist;


};

#endif // PROTAGONISTMODEL_H
