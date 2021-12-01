#ifndef VIEWHEALTH_H
#define VIEWHEALTH_H

#include <QGraphicsTextItem>

class ViewHealth: public QGraphicsTextItem{

public:
    ViewHealth(QGraphicsItem * parent=0);

    void increase();
    int getHealth();

private:
    int Health;

};

#endif // VIEWHEALTH_H
