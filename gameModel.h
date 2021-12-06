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
#include "world.h"
#include "PenemyModel.h"
#include "XenemyModel.h"
#include "tileType.h"
class GameModel
{
private:

    std::shared_ptr<protagonistModel> protagonist;
    std::vector<std::shared_ptr<TileModel>> tiles;
    std::vector<std::shared_ptr<HealthPackModel>>healthPacks;
    std::vector<std::shared_ptr<EnemyModel>> enemies;
    std::vector<std::shared_ptr<PenemyModel>> pEnemies;
    std::vector<std::shared_ptr<XenemyModel>> xEnemies;
    std::map<std::string,TileType> tileTypeMap;
    int rows;
    int cols;
    std::string sep =":";
    //const char sep=':';

public:
     GameModel();


    std::shared_ptr<protagonistModel> getProtagonist() const;
    void setProtagonist(std::shared_ptr<protagonistModel> &value);
    std::vector<std::shared_ptr<TileModel> > getTiles() const;
    void setTiles(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<HealthPackModel>>getHealthPacks()const;
    void setHealthPacks(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<EnemyModel> > getEnemies()const;
    void setEnemies(std::vector<std::unique_ptr<Enemy> > &value);
    std::vector<std::shared_ptr<PenemyModel> > getPEnemies()const;
    std::vector<std::shared_ptr<XenemyModel> > getXEnemies()const;
    TileType getTileType(int xposTile,int YposTile);
    std::shared_ptr<TileModel>getTileAtAPos(const int &xpos,const int &ypos);
    void clearProtagonistFromMap();
    void updateProtagonistPositionInMap();
    int getRows() const;
    int getCols() const;
    void setRows(int newRows);
    void setCols(int newCols);
    void printMap();//for testing purpose, delete after once the game is working


};


#endif // GAMEMODEL_H
