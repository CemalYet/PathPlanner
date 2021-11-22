#ifndef XENEMYMODEL_H
#define XENEMYMODEL_H
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include "enemyModel.h"
#include "gameModel.h"

class XEnemy: public Enemy
{
    Q_OBJECT
public:
    XEnemy(int xPosition, int yPosition, float strength);
    ~XEnemy() override = default;
    float getShapeType() const;
    void setShapeType(float value);

public slots:
    bool status();

signals:
    void shapeTypeUpdated(int value);

private:
    enum shapeType {cute, Mad, furious, dead};
};

#endif // XENEMYMODEL_H
