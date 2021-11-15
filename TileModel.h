#ifndef TILEMODEL_H
#define TILEMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include <bits/shared_ptr.h>
#include "world.h"


class  TileModel
{
private:
    std::shared_ptr<TileModel> tile;


public:
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<Tile> > getTiles() const;
    void setTiles(std::vector<std::shared_ptr<Tile> > &value);
    void addAll( std::vector<std::shared_ptr<Tile>> &tiles);
    void addTile(std::shared_ptr<Tile> tile);

};


#endif // TILEMODEL_H
