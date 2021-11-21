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
          cout<<'['<<e->getTile()->getXPos()<<','<<e->getTile()->getYPos()<<"] "<<e->isObstacle()<<endl;
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
      auto protagonist_model=make_shared<protagonistModel>();
      protagonist_model->setProtagonist(protagonist);
      auto protagonist_gamemodel = protagonist_model->getProtagonist();
      gameModel->setProtagonist(protagonist_model);
      auto actual_protagonist=gameModel->getProtagonist();





    std::cout<< "protagonist at ["<<actual_protagonist->getProtagonist()->getXPos()<<", "<< actual_protagonist->getProtagonist()->getYPos()<<"]"<<std::endl;
    actual_protagonist->getProtagonist()->setHealth(98.0);

    //TEST PROTAGONIST MODEL


    actual_protagonist->moveRight();
    actual_protagonist->moveRight();
    actual_protagonist->moveRight();
    actual_protagonist->moveLeft();
    actual_protagonist->moveUp();
    actual_protagonist->moveUp();
    actual_protagonist->moveDown();
    std::cout<< "protagonist move to position ["<<actual_protagonist->getProtagonist()->getXPos()<<", "<< actual_protagonist->getProtagonist()->getYPos()<<"]"<<std::endl;
    std::cout<<"Protagonist has "<<actual_protagonist->getProtagonist()->getHealth()<<" health"<<std::endl;
    protagonist_model->decreaseHealth(15.6);
    std::cout<<"Protagonist has been attacked new health is "<<actual_protagonist->getProtagonist()->getHealth()<<std::endl;
    std::cout<<"Protagonist has "<<actual_protagonist->getProtagonist()->getEnergy()<<" energy"<<std::endl;
    protagonist_model->decreaseEnergy(0.9);
    std::cout<<"Protagonist lost energy new energy is "<<actual_protagonist->getProtagonist()->getEnergy()<<std::endl;


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

