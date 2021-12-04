#include "gameModel.h"


GameModel::GameModel()
{

}
std::shared_ptr<protagonistModel> GameModel::getProtagonist() const
{
   return protagonist;
}

void GameModel::setProtagonist(std::shared_ptr<protagonistModel> &value)
{
  protagonist = value;
}


std::vector<std::shared_ptr<TileModel> > GameModel::getTiles() const
{
  return tiles;
}


void GameModel::setTiles(std::vector<std::unique_ptr<Tile> > &value)
{
    for(auto &tile:value){
        auto tile_model= std::make_shared<TileModel>();
        if(tile->getValue() != std::numeric_limits<float>::infinity()){
            tile->setValue(abs(1.001-(tile->getValue())));
    }
          tile_model->setTile(std::move(tile));
          tiles.push_back(tile_model);
        }
}

std::vector<std::shared_ptr<HealthPackModel> > GameModel::getHealthPacks() const
{
    return healthPacks;
}

void GameModel::setHealthPacks( std::vector<std::unique_ptr<Tile> > &value)
{
    for(auto &t:value){
       auto healthpack_model=std::make_shared<HealthPackModel>();
       healthpack_model->setHealthPack(std::move(t));
       healthPacks.push_back(healthpack_model);
    }
}
std::vector<std::shared_ptr<EnemyModel>> GameModel::getEnemies() const
{
    return enemies;
}

void GameModel::setEnemies(std::vector<std::unique_ptr<Enemy> > &value)
{
    for(auto &enemy:value){
            std::shared_ptr<PEnemy> penemy (qobject_cast<PEnemy*>(enemy.get()));
            if (  penemy != nullptr){ //if it is penemy
                auto pEnemy_model=std::make_shared<PenemyModel>();
                pEnemy_model->setPEnemy(std::move(penemy));
                pEnemies.push_back(pEnemy_model);


            } else {
                auto enemy_model=std::make_shared<EnemyModel>();
                enemy_model->setEnemy(std::move(enemy));
                enemies.push_back(enemy_model);
            }
         }
}

std::vector<std::shared_ptr<PenemyModel> > GameModel::getPEnemies() const
{
    return pEnemies;
}


