#ifndef VIEWTILE_H
#define VIEWTILE_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "TileModel.h"

class  ViewTile
{
public:
    std::shared_ptr<TileModel> healthPack;

    void selectNearestTile();

};


#endif // VIEWTILE_H

