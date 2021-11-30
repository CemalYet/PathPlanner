#include "ViewTile.h"
#include <sstream>

ViewTile::ViewTile()
{

}

QString ViewTile::viewTileText(int &Xpos, int &Ypos, float &value)
{
    //tile_text=new QGraphicsRectItem(Xpos*width,Ypos*width, width,width);
    //return tile_text;
    //auto tile_text=new QGraphicsRectItem(Xpos*width,Ypos*width, width,width);//22.5
    //QString line=new QStringBuilder<QString,QString>();

     /* std::stringstream ss;
      int jfrom=Xpos*width;
      int ifrom=Ypos*width;

      for (int j = jfrom; j < (jfrom+width); j++) {
              for (int i = ifrom; i < (ifrom+width); i++) {
                  if (i == ifrom|| i == ifrom+width-1|| j == ifrom || j == jfrom+width-1)
                      ss << "*";
                  else
                      ss << "  ";
              }
              ss << "\n";
          }

   return  QString::fromStdString(ss.str());*/
    tileTextview=std::make_shared<StringTextView>(Xpos,Ypos,value);
    return tileTextview->drawTextTile();

}

void ViewTile::selectNearestTile()
{

}
