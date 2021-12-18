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
#include "XenemyModel.h"
#include "tileType.h"


class GameModel
{

private:

    int rows;
    int cols;
    std::shared_ptr<protagonistModel> protagonist;
    std::vector<std::shared_ptr<TileModel>> tiles;
    std::vector<std::shared_ptr<HealthPackModel>>healthPacks;
    std::vector<std::shared_ptr<EnemyModel>> enemies;
    std::vector<std::shared_ptr<PenemyModel>> pEnemies;
    std::vector<std::shared_ptr<XenemyModel>> xEnemies;
    std::map<std::string,TileType> tileTypeMap;
    std::map<std::string,std::shared_ptr<Enemy>> enemyTileMap;
    std::map<std::string,std::shared_ptr<HealthPackModel>> healthTileMap;
    std::string sep =":";
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
    std::vector<std::shared_ptr<XenemyModel> > getXEnemies()const {
        return xEnemies;
    };
    void setXEnemies();

    TileType getTileType(int xposTile,int YposTile);
    std::shared_ptr<Enemy>getEnemyTileFromEnemyTileMap(const int &xpos,const int &ypos);
    std::shared_ptr<HealthPackModel>getHealthPackFromHealthTileMap(const int &xpos,const int &ypos);
    void setTileBlockedIntileTypeMap(const int &xpos,const int &ypos);
    void clearProtagonistFromMap(int prevXpos,int prevYPos);
    void updateProtagonistPositionInMap();
    void printMap();//for testing purpose, delete after once the game is working

    //pathplanner needs it
    const std::map<std::string, std::shared_ptr<Enemy> > &getEnemyTileMap() const;


};


#endif // GAMEMODEL_H
