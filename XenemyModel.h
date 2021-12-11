#ifndef XENEMYMODEL_H
#define XENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include <queue>
#include <vector>
#include "world.h"
#include "world_global.h"



class XEnemy;

class XenemyModel
{
public:
    const std::shared_ptr<XEnemy> &getXenemy() const{return xenemy;};
    //void setXEnemy(const std::shared_ptr<XEnemy> &newXEnemy);
    //void setXEnemy(const std::shared_ptr<XEnemy> &newXEnemy, std::unique_ptr<GameModel> &gameModel);
    void setXEnemy( int x, int y);
    //std::vector<std::shared_ptr<XenemyModel> > getXEnemies()const;

private:
    std::shared_ptr<XEnemy> xenemy;
    //std::vector<std::shared_ptr<XenemyModel>> xEnemies;
    int xPosition;
    int yPosition;
};

//------------------------------------------------------------

class XEnemy: public Enemy
{
    Q_OBJECT
public:
    XEnemy(int xPosition, int yPosition, float strength);
    ~XEnemy() override = default;
    float getShapeType() const;
    void setShapeType(float value);
    float setEnergyBar(float value);
    void setXenemy(std::vector<std::unique_ptr<Enemy> > &value);


public slots:
    bool status();

signals:
    void shapeTypeUpdated(int value);

private:
    enum shapeType {cute, Mad, furious, dead};
    //std::shared_ptr<XEnemy> Xenemy;
    float energyBar;
    std::vector<std::shared_ptr<XEnemy>> Xenemy;

};

#endif // XENEMYMODEL_H
