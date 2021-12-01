#ifndef PENEMYMODEL_H
#define PENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <memory>
#include "world.h"



class  PenemyModel
{
public:
    const std::shared_ptr<PEnemy> &getPEnemy() const{return penemy;};
    void setPEnemy(const std::shared_ptr<PEnemy> &newPEnemy){penemy = newPEnemy;};
private:
    std::shared_ptr<PEnemy> penemy;

    void getEnemyPosition();

};

#endif // PENEMYMODEL_H
