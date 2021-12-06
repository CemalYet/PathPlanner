#ifndef STRINGTEXTVIEW_H
#define STRINGTEXTVIEW_H
#include<QString>
#include<QStringBuilder>
#include"tileType.h"


class StringTextView
{
private:
    int stringXpos;
    int stringYpos;
    float stringvalue;
    int width{5};
    TileType tileType;//values E,P etc type enum need to check
    QString tileDrawing;

public:
    StringTextView(int &Xpos, int &Ypos, float &value, TileType type);

   // const QString &drawTile() ;
    QString drawTextTile();
    void setTileType(TileType newTileType);
    TileType getTileType() const;
    int getStringXpos() const;
    int getStringYpos() const;
};

#endif // STRINGTEXTVIEW_H
