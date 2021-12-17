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
#include "ViewText.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include "textcommands.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void processTextCommand(QString userCommand);
    void createTextCommandToClassMap();

private slots:
    void on_radioButton_Text_clicked();  
    void on_executeButton_clicked();

    void on_radioButton_graphics_clicked();
    //void on_comboBox_activated(int index);
    void on_pushButton_2_clicked();  //zoom out
    void on_pushButton_3_clicked();  //zoomin
    void on_health_valueChanged(float value);

public slots:
    void updateEnergy(int value);
    void updateHealth(int value);
    void gameOverSlot(const QString &message);
    void updateMainWindowViewSlot(QString buildview);

    void mousePressEvent(QMouseEvent *ev) override;

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

    QGraphicsScene* scene;
    std::shared_ptr<World> world;

    std::shared_ptr<ViewText>gameTextView;
    QGraphicsItem* textViewItem;
    std::map<std::string,std::shared_ptr<TextCommands>>textCommandToClassMap;

    void keyPressEvent(QKeyEvent * event) override;
};
#endif // MAINWINDOW_H
