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
void showpq(
     priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost >  g)
{

    while (!g.empty()) {
        cout << '\t' << g.top()->getFinalCost();
        g.pop();
    }
    cout << '\n';
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",1,1);


    auto pathPlanner=make_shared<PathPlanner>(3.3);
    vector<pair<int,int>> dummy=pathPlanner->solution(4,4,world);
    auto tiles=pathPlanner->getGameBoard();

    cout<<"printing  path"<<endl;

    for (auto &d :dummy ) {
        for(int i=0;i<5;i++){
                cout<<"|";
                for(int y=0;y<5;y++){
                    if(i==d.first && y==d.second){
                        cout<<"p"<<" |";
                    } else{
                         cout<< tiles[i*5+y]->getValue()<<" |";
                    }
                }
                cout<<endl;
            }

        cout<<d.first<<d.second<<endl;
    }

   /* priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost > openList;
    openList.push(make_shared<Node>(2,2,2.2,nullptr));
    openList.push(make_shared<Node>(2,2,3.2,nullptr));
    openList.push(make_shared<Node>(2,2,4.2,nullptr));
    showpq(openList);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

