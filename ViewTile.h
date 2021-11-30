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
#include "QGraphicsRectItem"
#include "QStringBuilder"
#include "QString"
#include "stringtextview.h"



class  ViewTile
{
private:
     static const int width=7;
     QGraphicsRectItem * tile_text;
     QString first="---";
     QString second="+";

public:
    std::shared_ptr<TileModel> healthPack;
    ViewTile();
    QString viewTileText(int &Xpos,int &Ypos,float &value);
    std::shared_ptr<StringTextView> tileTextview;
    void selectNearestTile();

};

#endif // VIEWTILE_H

