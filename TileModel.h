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
    std::shared_ptr<Tile> tile;

public:
    TileModel() {}
    bool isObstacle();
    void setInfinity();

    const std::shared_ptr<Tile> &getTile() const{return tile;};
    void setTile(const std::shared_ptr<Tile> &newTile){tile = newTile;};
};


#endif // TILEMODEL_H
