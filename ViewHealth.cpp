#include "ViewHealth.h"

ViewHealth::ViewHealth(QWidget *parent)
{
   Health = 100;

   //i will draw the text
   //setPlainText("Health:" + QString::number(Health));
   //setDefaultTextColor(Qt::red);
}

void ViewHealth::increase()
{
    Health++;
}

int ViewHealth::getHealth()
{
    return Health;
}
