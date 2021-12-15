#include "viewTiletext.h"


ViewTileText::ViewTileText(int &Xpos, int &Ypos, float &value)
{
    //stringTextTile=std::make_shared<StringTextView>(Xpos,Ypos,value,"   ");
    //stringTextTile=std::make_shared<StringTextView>(Xpos,Ypos,value,"E");
}
const std::shared_ptr<StringTextView> &ViewTileText::getStringTextTile() const
{
    return stringTextTile;
}



