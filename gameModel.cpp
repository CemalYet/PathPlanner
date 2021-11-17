#include "gameModel.h"


GameModel::GameModel()
{

}
std::shared_ptr<Protagonist> GameModel::getProtagonist() const
{
   return protagonist;
}

void GameModel::setProtagonist(std::unique_ptr<Protagonist> &value)
{
  protagonist = std::move(value);
}


std::vector<std::shared_ptr<Tile> > GameModel::getTiles() const
{
  return tiles;
}


void GameModel::setTiles(std::vector<std::unique_ptr<Tile> > &value)
{
    for(auto &tile:value){
          tiles.push_back(std::move(tile));
        }
}

std::vector<std::shared_ptr<Tile> > GameModel::getHealthPacks() const
{
    return healthPacks;
}

void GameModel::setHealthPacks( std::vector<std::unique_ptr<Tile> > &value)
{
    for(auto &tile:value){
       healthPacks.push_back(std::move(tile));
    }
}
std::vector<std::shared_ptr<Enemy> > GameModel::getEnemies()
{
    for(auto & entry: enemyMap)
        enemies.push_back(entry.second);
    return enemies;
}

void GameModel::setEnemies(std::vector<std::unique_ptr<Enemy> > &value)
{
    for(auto &enemy:value){
            std::shared_ptr<PEnemy> penemy (qobject_cast<PEnemy*>(enemy.get()));
            if (  penemy != nullptr){ //if it is penemy
                std::string XPosTile=std::to_string(penemy->getXPos());
                std::string YPosTile=std::to_string(penemy->getYPos());
                penemyMap[XPosTile+sep+YPosTile]=penemy;
            } else {
                std::string XPosTile=std::to_string(enemy->getXPos());
                std::string YPosTile=std::to_string(enemy->getYPos());
                enemyMap[XPosTile+sep+YPosTile]=std::move(enemy);
            }
         }
}

std::vector<std::shared_ptr<Enemy> > GameModel::getPEnemies()
{
    for(auto & entry: penemyMap)
        pEnemies.push_back(entry.second);
    return pEnemies;
}


