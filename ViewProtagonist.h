#ifndef VIEWPROTAGONIST_H
#define VIEWPROTAGONIST_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "protagonistModel.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "world.h"
#include "world_global.h"
#include "TileModel.h"
#include "ViewPenemy.h"
//#include "ViewXenemy.h"
#include "gameModel.h"
//#include "XenemyModel.h"



class  ViewProtagonist :public QGraphicsPixmapItem
{
public:
    ViewProtagonist(QGraphicsItem * parent=0);
    ViewPenemy * viewPEnemy_defeated;

    //void keyPressEvent(QKeyEvent * event) override;
    void selectNearestEnemy();
    void addAll(std::vector<std::unique_ptr<Tile>> &tiles,std::vector<std::unique_ptr<Tile>> &data);
    std::shared_ptr<Protagonist> getProtagonist_view() const{return protagonist;};
    void setProtagonist(std::unique_ptr<Protagonist> &value){protagonist = std::move(value);};

    void moveRight(const int protagonistXPos, const int protagonistYPos);
    void moveLeft(const int protagonistXPos, const int protagonistYPos);
    void moveUp(const int protagonistXPos, const int protagonistYPos);
    void moveDown(const int protagonistXPos, const int protagonistYPos);

private:
    std::shared_ptr<Tile> tile;
    std::shared_ptr<Protagonist> protagonist;
    std::shared_ptr<ViewProtagonist> protagonist_view;
};

#endif // VIEWPROTAGONIST_H

