#include "viewTiletext.h"

ViewTileText::ViewTileText(int &Xpos, int &Ypos, float &value)
{
    stringTextTile=std::make_shared<StringTextView>(Xpos,Ypos,value);
}


