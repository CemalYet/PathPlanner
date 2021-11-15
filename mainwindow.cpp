#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world_global.h"
#include "world.h"
#include "node.h"
#include <queue>
#include <vector>
#include <memory>

using namespace std;
//void showpq(priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost >  g)
//{

//    while (!g.empty()) {
//        cout << '\t' << g.top()->getFinalCost();
//        g.pop();
//    }
//    cout << '\n';
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",1,1);
    auto tile=world->getTiles();
    auto enemy=world->getEnemies();

    auto health=world->getHealthPacks();


     cout<<"TILE VALUES"<<endl;
     //int eX=enemy[0]->getXPos();
     //int eY=enemy[0]->getYPos();



    for(int i=0;i<5;i++){
        cout<<"|";
        for(int y=0;y<5;y++){
            tile[i*5+y]->getValue();

            cout<<tile[i*5+y]->getValue();
        }
        cout<<endl;
    }

    cout<<enemy[0]->getXPos()<<endl;
    cout<<enemy[0]->getYPos()<<endl;



//      priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost > openList;
//    openList.push(make_shared<Node>(2,2,2.2,nullptr));
//    openList.push(make_shared<Node>(2,2,3.2,nullptr));
//    openList.push(make_shared<Node>(2,2,4.2,nullptr));
//      showpq(openList);
}

MainWindow::~MainWindow()
{
    delete ui;
}

