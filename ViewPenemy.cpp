#include "ViewPenemy.h"

ViewPenemy::ViewPenemy(QGraphicsItem *parent, const int &x_pos, const int &y_pos)
{
    setPixmap(QPixmap(":/images/Raiden.png"));
    setPos(x_pos, y_pos);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void ViewPenemy::selectNearestEnemy()
{

}
