#include "stringtextview.h"
#include <sstream>

StringTextView::StringTextView(int &Xpos, int &Ypos, float &value):
    stringXpos{Xpos},stringYpos{Ypos},stringvalue{value}
{

}

QString StringTextView::drawTextTile()
{
    std::stringstream ss;
  //  int jfrom=stringXpos*width;
   // int ifrom=stringYpos*width;

   /* for (int j = jfrom; j < (jfrom+width); j++) {
            for (int i = ifrom; i < (ifrom+width); i++) {
                if (i == ifrom|| i == ifrom+width-1|| j == ifrom || j == jfrom+width-1)
                    ss << "*";
                if (i==(ifrom+width)/2 &&j==(jfrom+width)/2)
                    ss << "E";
                else
                    ss << "  ";
            }
            ss << "\n";
        }*/
    QString ldimension="- ";
    QString upperdimension="* ";
    for (int i = 0; i < width; ++i){
          upperdimension= upperdimension%ldimension;
        }
    upperdimension=upperdimension%"*";
   // QString wdimension="* ";
    QString gap="  ";
    QString midwidthText="* ";
    for (int i = 0; i < width; ++i){
        if(i == width/2)
        {
             midwidthText= midwidthText%"E";
        }
        else
        {

          midwidthText= midwidthText%gap;
        }
    }
    midwidthText=midwidthText%"*";
    QString box=upperdimension%"\n"%midwidthText%"\n"%upperdimension;
    //return  QString::fromStdString(ss.str());
    return box;
}
