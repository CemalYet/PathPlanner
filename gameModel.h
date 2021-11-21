#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <memory>
#include "world.h"
#include "TileModel.h"
#include "protagonistModel.h"


class GameModel
{
private:

    std::shared_ptr<protagonistModel> protagonist;
    std::vector<std::shared_ptr<TileModel>> tiles;

    //Need to be changed to models name
    std::vector<std::shared_ptr<Tile>> healthPacks;
    std::vector<std::shared_ptr<Enemy>> pEnemies;
    std::vector<std::shared_ptr<Enemy> >  enemies;
    std::map<std::string,std::shared_ptr<PEnemy>> penemyMap;
    std::map<std::string,std::shared_ptr<Enemy>> enemyMap;
    int numCols;
    int numRows;
    std::string sep =":";
public:
     GameModel();


    std::shared_ptr<protagonistModel> getProtagonist() const;
    void setProtagonist(std::shared_ptr<protagonistModel> &value);
    std::vector<std::shared_ptr<TileModel> > getTiles() const;
    void setTiles(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<Tile> > getHealthPacks() const;
    void setHealthPacks(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<Enemy> > getEnemies();
    void setEnemies(std::vector<std::unique_ptr<Enemy> > &value);
    std::vector<std::shared_ptr<Enemy> > getPEnemies();


    int getNumCols() const;
    int getNumRows() const;
};


#endif // GAMEMODEL_H
