#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <memory>
#include "world.h"

class GameModel
{
private:

    std::shared_ptr<Protagonist> protagonist;
    std::vector<std::shared_ptr<Tile>> tiles;
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
    //enemyModel::selectNearestEnemy();
    //TileModel::findFirstHealthPack();


    std::shared_ptr<Protagonist> getProtagonist() const;
    void setProtagonist(std::unique_ptr<Protagonist> &value);
    std::vector<std::shared_ptr<Tile> > getTiles() const;
    void setTiles(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<Tile> > getHealthPacks() const;
    void setHealthPacks(std::vector<std::unique_ptr<Tile> > &value);
    std::vector<std::shared_ptr<Enemy> > getEnemies();
    void setEnemies(std::vector<std::unique_ptr<Enemy> > &value);
    std::vector<std::shared_ptr<Enemy> > getPEnemies();


};


#endif // GAMEMODEL_H
