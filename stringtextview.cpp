#include "stringtextview.h"
//#include <sstream>

StringTextView::StringTextView(int &Xpos, int &Ypos, float &value, TileType type):
    stringXpos{Xpos},stringYpos{Ypos},stringvalue{value},tileType{type}
{
    //tileDrawing=drawTextTile();
}

/*const QString &StringTextView::tileDrawing()
{
    tileDrawing=drawTextTile();
    return tileDrawing;
}*/

void StringTextView::setTileType(TileType newTileType)
{
    tileType = newTileType;
}

TileType StringTextView::getTileType() const
{
    return tileType;
}

int StringTextView::getStringXpos() const
{
    return stringXpos;
}

int StringTextView::getStringYpos() const
{
    return stringYpos;
}

QString StringTextView::drawTextTile()
{
    QString gap="  ";
    QString midwidthText="|";
    for (int i = 0; i < 3; ++i){
        if(i == 1)
        {
             //type=QString("<span style=" color:#ff00;">%1</span").arg(">>>>");
             //QString type("<FONT COLOR=red>%1</FONT>");
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
