#include "TileModel.h"


std::vector<std::shared_ptr<Tile> > TileModel::getTiles() const
{

}

void TileModel::setTiles(std::vector<std::shared_ptr<Tile> > &value)
{
    for(auto &tile:value){
           tiles.push_back(std::move(tile));
        }
}


void TileModel::addTile(std::shared_ptr<Tile> tile) {

        tiles.push_back(std::move(tile));
        //cout<<"ahdash "<<tile->getXPos()<<tile->getYPos()<<endl;
        //return tile->getValue();
}

void TileModel::addAll( std::vector<std::shared_ptr<Tile>> &tiles){
    for(unsigned int i=0;i<tiles.size();i++){
        addTile(move(tiles[i]));
    }

}
