#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameModel.h"
#include "world.h"
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include <QGraphicsView>
#include "ViewProtagonist.h"
#include "ViewHealth.h"
#include "ViewPenemy.h"
#include "ViewXenemy.h"
#include <QKeyEvent>
#include "XenemyModel.h"
#include "ViewHealthPack.h"
#include <QGraphicsPolygonItem>
#include <QProgressBar>
#include <QLayout>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_health_valueChanged(float value);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<GameModel> gameModel;
    //--------------------------------------
    QGraphicsScene * scene;
    ViewProtagonist * viewProtagonist;
    ViewHealth * viewHealth;
    ViewPenemy * viewPenemy;
    ViewXenemy * viewXenemy;
    XenemyModel * xenemy;
    ViewHealthPack * healtPack;


    void keyPressEvent(QKeyEvent * event) override;
    //void addTile(std::unique_ptr<Tile> tiles,std::vector<std::unique_ptr<Tile>> &data) ;
};
#endif // MAINWINDOW_H
