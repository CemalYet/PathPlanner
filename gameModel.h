#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <memory>
#include "world.h"
#include "TileModel.h"
#include "protagonistModel.h"
#include "enemyModel.h"
#include "HealthPackModel.h"
#include "PenemyModel.h"
//#include "ViewProtagonist.h"
#include "XenemyModel.h"
#include <QGraphicsRectItem>


class GameModel
{
private:

    int rows;
    int cols;
    std::shared_ptr<protagonistModel> protagonist;
    //std::shared_ptr<ViewProtagonist> protagonist_view;
    std::vector<std::shared_ptr<TileModel>> tiles;
    std::vector<std::shared_ptr<HealthPackModel>>healthPacks;
    std::vector<std::shared_ptr<EnemyModel>> enemies;
    std::vector<std::shared_ptr<PenemyModel>> pEnemies;
    std::vector<std::shared_ptr<XenemyModel>> xEnemies;

public:
    GameModel();
    void setRows(int newRows);
    void setCols(int newCols);
    int getRows() const;
    int getCols() const;
    std::shared_ptr<protagonistModel> getProtagonist() const;
    void setProtagonist(std::shared_ptr<protagonistModel> &value);
    std::vector<std::shared_ptr<TileModel> > getTiles() const;
    void setTiles(std::vector<std::unique_ptr<Tile> > &value);
    std::shared_ptr<TileModel> getTileAtAPos(const int &xpos, const int &ypos);
    std::vector<std::shared_ptr<HealthPackModel>>getHealthPacks()const;
    void setHealthPacks(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<EnemyModel> > getEnemies()const;
    void setEnemies(std::vector<std::unique_ptr<Enemy> > &value);
    std::vector<std::shared_ptr<PenemyModel> > getPEnemies()const;
    std::vector<std::shared_ptr<XenemyModel> > getXEnemies()const;
};


#endif // GAMEMODEL_H
