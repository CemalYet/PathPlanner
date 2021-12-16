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
#include "ViewGraphical.h"
#include <QKeyEvent>
#include "XenemyModel.h"
#include "ViewHealthPack.h"
#include <QGraphicsPolygonItem>
#include <QProgressBar>
#include <QLayout>
#include <QPainter>
#include<QPainterPath>
#include <QMouseEvent>
#include "pathplanner.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *ev);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_health_valueChanged(float value);  
    void on_radioButton_clicked();

    void Mouse_current_pos();
    void Mouse_Pressed();
    void Mouse_left();

    void on_radioButton_2_clicked();


    void on_horizontalSlider_sliderMoved(int position);

public slots:
    void updateEnergy(float value);
    void updateHealth(float value);



private:
    Ui::MainWindow *ui;
    std::shared_ptr<GameModel> gameModel;
    std::shared_ptr<PathPlanner> path;
    std::shared_ptr<ViewGraphical> graphicView;
    QGraphicsItem * graphicViewItem;
    //--------------------------------------
    QGraphicsScene * scene_graphics;
    ViewProtagonist * viewProtagonist;
    ViewHealth * viewHealth;
    ViewPenemy * viewPenemy;
    ViewXenemy * viewXenemy;
    ViewXenemy * xenemy;
    ViewHealthPack * healtPack;

    //void paintEvent(QPaintEvent *event);
//    int x() const;
//    int y() const;
    void mouseMoveEvent(QMouseEvent *event);


    void keyPressEvent(QKeyEvent * event) override;
    //void addTile(std::unique_ptr<Tile> tiles,std::vector<std::unique_ptr<Tile>> &data) ;
};
#endif // MAINWINDOW_H
