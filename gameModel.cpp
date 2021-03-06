#include "gameModel.h"

int GameModel::getRows() const
{
    return rows;
}

int GameModel::getCols() const
{
    return cols;
}

void GameModel::setRows(int newRows)
{
    rows = newRows;
}

void GameModel::setCols(int newCols)
{
    cols = newCols;
}

void GameModel::printMap()
{
    for(auto &map:tileTypeMap){
    std::cout<<"[" <<map.first<<", "<<getStringForEnum(map.second)<<"]"<<std::endl;
    }
}

const std::map<std::string, std::shared_ptr<Enemy> > &GameModel::getEnemyTileMap() const
{
    return enemyTileMap;
}


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
    updateProtagonistPositionInMap();
}

void GameModel::clearProtagonistFromMap(int prevXpos,int prevYPos){
    auto protagonistXPos=std::to_string(prevXpos);
    auto protagonistYPos=std::to_string(prevYPos);
    tileTypeMap.erase(protagonistXPos+sep+protagonistYPos);
}

void GameModel::updateProtagonistPositionInMap()
{
    auto protagonistXPos=std::to_string(protagonist->getProtagonist()->getXPos());
    auto protagonistYPos=std::to_string(protagonist->getProtagonist()->getYPos());
    //std::cout<<"protogonist at "<< protagonistXPos << protagonistYPos << std::endl;
    tileTypeMap[protagonistXPos+sep+protagonistYPos]=TileType::Protagonist;
}


std::vector<std::shared_ptr<TileModel> > GameModel::getTiles() const
{
  return tiles;
}


/*void GameModel::setTiles(std::vector<std::unique_ptr<Tile> > &value)
<<<<<<< gameModel.cpp
{
    for(auto &tile:value){
        auto tile_model= std::make_shared<TileModel>();
        if(tile->getValue() != std::numeric_limits<float>::infinity()){
            //std::cout<<1/tile->getValue()<<std::endl;
            tile->setValue(abs(1-(tile->getValue())));
    }
          tile_model->setTile(std::move(tile));
          tiles.push_back(tile_model);      
        }
}*/
//testing :if not working uncomment top code
void GameModel::setTiles(std::vector<std::unique_ptr<Tile> > &value)
{   tiles.clear();
    for(auto &tile:value){
        auto tile_model= std::make_shared<TileModel>();
        if(tile->getValue() != std::numeric_limits<float>::infinity()){
            //std::cout<<1/tile->getValue()<<std::endl;
            tile->setValue(abs(1-(tile->getValue())));
        }
        else if(tile->getValue() == std::numeric_limits<float>::infinity()){
            auto tileXPos=std::to_string(tile->getXPos());
            auto tileYPos=std::to_string(tile->getYPos());
            tileTypeMap[tileXPos+sep+tileYPos]=TileType::Blocked;
            //std::cout<<"blockz"<<std::endl;
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
{   healthPacks.clear();
    for(auto &t:value){
       auto healthpack_model=std::make_shared<HealthPackModel>();
       healthpack_model->setHealthPack(std::move(t));
       healthPacks.push_back(healthpack_model);
       auto healthPackXPos=std::to_string(healthpack_model->getHealthPack()->getXPos());
       auto healthPackYPos=std::to_string(healthpack_model->getHealthPack()->getYPos());
       tileTypeMap[healthPackXPos+sep+healthPackYPos]=TileType::HealthPack;
      // healthTileMap[healthPackXPos+sep+healthPackYPos]=healthpack_model->getHealthPack();
       healthTileMap[healthPackXPos+sep+healthPackYPos]=healthpack_model;
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
                auto penemyXPos=std::to_string(pEnemy_model->getPEnemy()->getXPos());
                auto penemyYPos=std::to_string(pEnemy_model->getPEnemy()->getYPos());
                tileTypeMap[penemyXPos+sep+penemyYPos]=TileType::PEnemy;
                enemyTileMap[penemyXPos+sep+penemyYPos]=pEnemy_model->getPEnemy();


            } else {
                auto enemy_model=std::make_shared<EnemyModel>();
                enemy_model->setEnemy(std::move(enemy));
                enemies.push_back(enemy_model);
                auto enemyXPos=std::to_string(enemy_model->getEnemy()->getXPos());
                auto enemyYPos=std::to_string(enemy_model->getEnemy()->getYPos());
                tileTypeMap[enemyXPos+sep+enemyYPos]=TileType::Enemy;
                enemyTileMap[enemyXPos+sep+enemyYPos]=enemy_model->getEnemy();
            }
         }
}

TileType GameModel:: getTileType(int xposTile,int YposTile){
    std::map<std::string,TileType>::iterator it;

    it= tileTypeMap.find(std::to_string(xposTile)+sep+std::to_string(YposTile));
    if (it==tileTypeMap.end()){
        return TileType::NormalTile;
    }else{
        return it->second;
    }
}

std::shared_ptr<TileModel> GameModel::getTileAtAPos(const int &xpos, const int &ypos)
{
    return tiles.at(xpos+cols*ypos);
}

std::shared_ptr<Enemy> GameModel::getEnemyTileFromEnemyTileMap(const int &xpos, const int &ypos)
{
    std::map<std::string,std::shared_ptr<Enemy>>::iterator it;
    it= enemyTileMap.find(std::to_string(xpos)+sep+std::to_string(ypos));
    return it->second;
}

std::shared_ptr<HealthPackModel> GameModel::getHealthPackFromHealthTileMap(const int &xpos, const int &ypos)
{
    std::map<std::string,std::shared_ptr<HealthPackModel>>::iterator it;
    //it= healthTileMap.find(std::to_string(xpos)+sep+std::to_string(ypos));
    it= healthTileMap.find(std::to_string(xpos)+sep+std::to_string(ypos));
    return it->second;
}

/*void GameModel::setTileBlockedIntileTypeMap(const int &xpos, const int &ypos)
{
     tileTypeMap[std::to_string(xpos)+sep+std::to_string(ypos)]=TileType::Blocked;
}*/

void GameModel::setTileBlockedIntileTypeMap(const int &xpos, const int &ypos)
{
     tileTypeMap[std::to_string(xpos)+sep+std::to_string(ypos)]=TileType::Blocked;
}


std::vector<std::shared_ptr<PenemyModel> > GameModel::getPEnemies() const
{
    return pEnemies;
}

void GameModel::setXEnemies()
{               xEnemies.clear();
                int xPos=0; int yPos=0;
                for(auto &x_enemy:pEnemies){
                    auto xEnemy =std::make_shared<XenemyModel> ();
                    //cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
                    xPos = x_enemy->getPEnemy()->getXPos() + rand() % 1000;
                    if(xPos > 2200){
                        xPos = xPos - rand() % 25 + 1;
                    }
                    yPos = x_enemy->getPEnemy()->getYPos() + rand() % 1000;
                    if (yPos > 2200){
                        yPos = yPos - rand() % 25 + 1;
                    }
                    xEnemy->setXPosition(xPos);
                    xEnemy->setYPosition(yPos);
                    xEnemies.push_back(xEnemy);
                 }
}
