#ifndef VIEWTILETEXT_H
#define VIEWTILETEXT_H

#include "ViewTile.h"
#include "stringtextview.h"

class ViewTileText : public ViewTile
{
private:
   std::shared_ptr<StringTextView>stringTextTile;

public:
   ViewTileText(int &Xpos, int &Ypos, float &value);
   const std::shared_ptr<StringTextView> &getStringTextTile() const;
};

#endif // VIEWTILETEXT_H
