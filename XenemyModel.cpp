#include "XenemyModel.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsScene>

XenemyModel::XenemyModel(QGraphicsItem *parent)
{
    //list of points that create a polygon: (1,0), (2,0), (3,1), (3,2), (2,3), (1,3), (0,2), (0,1)
    // set the graphics
    setPixmap(QPixmap(":/images/sindel.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 65;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    attackBoundry = new QGraphicsPolygonItem(QPolygonF(points),this);
    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF xenemy_center(x()+25,y()+25);
    QLineF ln(poly_center,xenemy_center);
    attackBoundry->setPos(x()+ln.dx(),y()+ln.dy());

    //create a timer to attack the protagonist
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(aquire_target()));
    timer->start(1000);

    attack_dest = QPointF(800,0);
}

double XenemyModel::distanceTO(QGraphicsItem *item)
{
    //draw a line between the xenemy and the item to calculate the distacnce
    QLineF ln(pos(), item->pos());
    return ln.length();
}

void XenemyModel::fire()
{
    Projectile * projectile = new Projectile();
    projectile->setPos(x()+20, y()+20);

    QLineF ln(QPointF(x()+20, y()+20), attack_dest);
    int angle = ln.angle();

    projectile->setRotation(angle);
    scene()->addItem(projectile);
}

void XenemyModel::aquire_target()
{
    QList<QGraphicsItem *> colliding_items = attackBoundry->collidingItems();

    //Do not attack when there is no enemies by checking the size of the colliding list
    //if the list has only one object = xenemy itself, then do not attack

    if(colliding_items.size() == 1){
        hasTarget = false;
        return;
    }

    double closet_distance = 300;
    QPointF closest_pt = QPointF(0,0);

    for (size_t i=0, n=colliding_items.size(); i<n; i++){
        ViewProtagonist* protagonist = dynamic_cast<ViewProtagonist *>(colliding_items[i]);  //if it's wrorong then the pointer will be set to null_ptr
        if (protagonist){     //if the casting is correct, then it's a protagonist pointer
            double this_dist = distanceTO(protagonist);
            if (this_dist < closet_distance){
                closet_distance = this_dist;
                closest_pt = colliding_items[i]->pos();
                hasTarget = true;
            }
        }
    }
    attack_dest = closest_pt;
    fire();
}
