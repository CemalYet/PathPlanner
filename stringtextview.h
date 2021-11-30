#ifndef STRINGTEXTVIEW_H
#define STRINGTEXTVIEW_H
#include<QString>
#include<QStringBuilder>


class StringTextView
{
private:
    int stringXpos;
    int stringYpos;
    float stringvalue;
    int width{5};
    QString tileType;//values E,P etc type enum need to check
    QString tileDrawing;
    QString drawTextTile();
public:
    StringTextView(int &Xpos, int &Ypos, float &value);

};

#endif // STRINGTEXTVIEW_H
