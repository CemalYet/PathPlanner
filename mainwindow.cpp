#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world_global.h"
#include "world.h"
#include "node.h"
#include "protagonistModel.h"
#include <queue>
#include <vector>
#include <memory>

using namespace std;

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
          std::vector<std::shared_ptr<Tile>> healthPacks;
        }


    auto penemies_gamemodel=gameModel->getPEnemies();
    std::cout<<"Penemies at location"<<std::endl;
    for(auto &e:penemies_gamemodel){
          cout<<'['<<e->getXPos()<<','<<e->getYPos()<<']'<<endl;
          std::cout<<"Xenemies at location"<<std::endl;
          cout<<'['<<e->getXPos() + rand() % 28+1 <<','<<e->getYPos() + rand() % 28+1<<']'<<endl;
        }

    auto protagonist=world->getProtagonist();
    gameModel->setProtagonist(protagonist);
    auto protagonist_gamemodel=gameModel->getProtagonist();
    std::cout<< "protagonist at ["<<protagonist_gamemodel->getXPos()<<", "<< protagonist_gamemodel->getYPos()<<"]"<<std::endl;
    //protagonist_gamemodel->setHealth(98.0);

    //TEST PROTAGONIST MODEL
    auto protagonist_model=make_shared<protagonistModel>();
    protagonist_model->setProtagonist(protagonist_gamemodel);
    protagonist_model->moveRight();
    protagonist_model->moveRight();
    protagonist_model->moveRight();
    protagonist_model->moveLeft();
    protagonist_model->moveUp();
    protagonist_model->moveUp();
    protagonist_model->moveDown();
    std::cout<< "protagonist move to position ["<<protagonist_model->getProtagonist()->getXPos()<<", "<< protagonist_model->getProtagonist()->getYPos()<<"]"<<std::endl;
    std::cout<<"Protagonist has "<<protagonist_gamemodel->getHealth()<<" health"<<std::endl;
    protagonist_model->decreaseHealth(15.6);
    std::cout<<"Protagonist has been attacked new health is "<<protagonist_model->getProtagonist()->getHealth()<<std::endl;
    std::cout<<"Protagonist has "<<protagonist_gamemodel->getEnergy()<<" energy"<<std::endl;
    protagonist_model->decreaseEnergy(0.9);
    std::cout<<"Protagonist lost energy new energy is "<<protagonist_model->getProtagonist()->getEnergy()<<std::endl;


    auto health=world->getHealthPacks();
    gameModel->setHealthPacks(health);
    auto healthpack_gamemodel=gameModel->getHealthPacks();
    std::cout<<"Healthpack at location"<<std::endl;
    for(auto &h:healthpack_gamemodel){
          cout<<'['<<h->getXPos()<<','<<h->getYPos()<<']'<<endl;
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

