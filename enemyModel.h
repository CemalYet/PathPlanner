#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "world.h"

class  EnemyModel
{
public:

    const std::shared_ptr<Enemy> &getEnemy() const{return enemy;};
    void setEnemy(const std::shared_ptr<Enemy> &newEnemy){enemy = newEnemy;};

private:
    std::shared_ptr<Enemy> enemy;

};

#endif // ENEMYMODEL_H
