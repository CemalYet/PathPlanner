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
    QString drawTextTile();
public:
    StringTextView(int &Xpos, int &Ypos, float &value, TileType type);

    const QString &getTileDrawing() const;
};

#endif // STRINGTEXTVIEW_H
