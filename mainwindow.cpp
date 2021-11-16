#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world_global.h"
#include "world.h"
#include "node.h"
#include <queue>
#include <vector>
#include <memory>
#include "pathplanner.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",1,1);


    auto pathPlanner=make_shared<PathPlanner>(world,0.2);
    vector<pair<int,int>> dummy=pathPlanner->solution(29,29);
    auto tiles=pathPlanner->getGameBoard();

    cout<<"PATH === "<<dummy.size()<<endl;

    for (auto &d :dummy ) {
        for(int i=0;i<world->getCols();i++){
                cout<<"|";
                for(int y=0;y<world->getRows();y++){
                    if(i==d.second && y==d.first){
                        cout<<"p"<<" |";
                    } else{
                         cout<< tiles[i*world->getCols()+y]->getValue()<<" |";
                    }
                }
                cout<<endl;
            }

        cout<<d.first<<d.second<<endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

