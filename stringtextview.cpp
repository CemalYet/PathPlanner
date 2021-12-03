#include "stringtextview.h"
//#include <sstream>

StringTextView::StringTextView(int &Xpos, int &Ypos, float &value, TileType type):
    stringXpos{Xpos},stringYpos{Ypos},stringvalue{value},tileType{type}
{
    tileDrawing=drawTextTile();
}

const QString &StringTextView::getTileDrawing() const
{
    return tileDrawing;
}

QString StringTextView::drawTextTile()
{
    QString gap="  ";
    QString midwidthText="|";
    for (int i = 0; i < 3; ++i){
        if(i == 1)
        {
            auto type=QString::fromStdString(getStringForEnum(tileType));
             midwidthText= midwidthText%type;
        }
        else
        {

          midwidthText= midwidthText%gap;
        }
    }
    return midwidthText;
}
