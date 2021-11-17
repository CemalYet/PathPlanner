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

    auto world = make_unique<World>();
    world->createWorld(":/images/worldmap.jpg",1,1);
    gameModel = std::make_unique<GameModel>();



    auto world_tiles=world->getTiles();
    gameModel->setTiles(world_tiles);
    auto gamemodel_tiles=gameModel->getTiles();
    cout<<"Tiles at location"<<endl;
    for(auto &e:gamemodel_tiles){
          cout<<'['<<e->getXPos()<<','<<e->getYPos()<<']'<<endl;
        }



    auto enemy=world->getEnemies();
    gameModel->setEnemies(enemy);
    auto enemies_gamemodel=gameModel->getEnemies();
    std::cout<<"enemies at location"<<std::endl;
    for(auto &e:enemies_gamemodel){
          cout<<'['<<e->getXPos()<<','<<e->getYPos()<<']'<<endl;
        }


    auto penemies_gamemodel=gameModel->getPEnemies();
    std::cout<<"Penemies at location"<<std::endl;
    for(auto &e:penemies_gamemodel){
          cout<<'['<<e->getXPos()<<','<<e->getYPos()<<']'<<endl;
        }

    auto protagonist=world->getProtagonist();
    gameModel->setProtagonist(protagonist);
    auto protagonist_gamemodel=gameModel->getProtagonist();
    std::cout<< "protagonist at ["<<protagonist_gamemodel->getXPos()<<", "<< protagonist_gamemodel->getYPos()<<"]"<<std::endl;

    auto health=world->getHealthPacks();
    gameModel->setHealthPacks(health);
    auto healthpack_gamemodel=gameModel->getHealthPacks();
    std::cout<<"Healthpack at location"<<std::endl;
    for(auto &h:healthpack_gamemodel){
          cout<<'['<<h->getXPos()<<','<<h->getYPos()<<']'<<endl;
        }






     //cout<<"TILE VALUES"<<endl;
     //int eX=enemy[0]->getXPos();
     //int eY=enemy[0]->getYPos();



  /* for(int i=0;i<5;i++){
        cout<<"|";
        for(int y=0;y<5;y++){
            tile[i*5+y]->getValue();

            cout<<tile[i*5+y]->getValue();
        }
        cout<<endl;
    }

    cout<<enemy[0]->getXPos()<<endl;
    cout<<enemy[0]->getYPos()<<endl;*/



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

