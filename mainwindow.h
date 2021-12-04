#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gameModel.h"
#include<string>
#include <iostream>
#include <vector>
#include <functional>
#include <QTimer>
#include <memory>
#include <QGraphicsView>
#include "ViewProtagonist.h"
#include "ViewHealth.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<GameModel> gameModel;
    //--------------------------------------
    QGraphicsScene * scene;
    ViewProtagonist * viewProtagonist;
    ViewHealth * viewHealth;
};
#endif // MAINWINDOW_H
