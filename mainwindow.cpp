#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world_global.h"
#include "world.h"
#include "node.h"
#include "protagonistModel.h"
#include "PenemyModel.h"
#include "enemyModel.h"
#include "pathplanner.h"
#include "XenemyModel.h"
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

/// (0,22) -> (1200,1205); maze3
/// (0,45) -> (999, 938)

       auto world = make_shared<World>();
       world->createWorld(":/images/worldmap.jpg",10,25);
       gameModel = std::make_unique<GameModel>();

       //set tiles
       auto world_tiles=world->getTiles();
       gameModel->setTiles(world_tiles);

//       //set All Type enemies
//       auto allEnemy=world->getEnemies();
//       gameModel->setAllTypeEnemies(allEnemy);


       //set enemies
       auto enemy=world->getEnemies();
       gameModel->setEnemies(enemy);

       //set health pack
       auto healthpack=world->getHealthPacks();
       gameModel->setHealthPacks(healthpack);

       //set protagonist
       auto protagonist=world->getProtagonist();
       auto protagonist_model=make_shared<protagonistModel>();
       protagonist_model->setProtagonist(protagonist);
       auto protagonist_gamemodel = protagonist_model->getProtagonist();
       gameModel->setProtagonist(protagonist_model);
       gameModel->getProtagonist()->getProtagonist()->setXPos(0);
       gameModel->getProtagonist()->getProtagonist()->setYPos(0);


       gameModel->setCols(world->getCols());
       gameModel->setRows(world->getRows());


//         cout<<"enemy number "<<gameModel->getEnemies().size()<<endl;
//         cout<<"P enemy number "<<gameModel->getPEnemies().size()<<endl;


      auto pathPlanner=make_shared<PathPlanner>(gameModel,1);
      auto autoplayPath=pathPlanner->autoPlay();


      if(autoplayPath.first){
          cout<<"you win "<<endl;
          cout<<autoplayPath.second.size()<<endl;
      }else{
          cout<<"game over"<<endl;
          cout<<autoplayPath.second.size()<<endl;
      }
      //cout<<"PATH === "<<autoplayPath.second.size()<<endl;


//     pair<float,vector<pair<int,int>>> dummy=pathPlanner->solution1(1200,1205);


//      cout<<"PATH === "<<dummy.second.size()<<endl;
//        for (auto d :dummy.second ) {
//            cout<<"X: " <<d.first<<" Y: "<< d.second<<endl;
//        }


//    auto world_tiles=world->getTiles();
//    gameModel->setTiles(world_tiles);
//    auto gamemodel_tiles=gameModel->getTiles();
//    cout<<"Tiles at location"<<endl;
//    for(auto &e:gamemodel_tiles){
//        cout<<'['<<e->getTile()->getXPos()<<','<<e->getTile()->getYPos()<<"] "<<e->isObstacle()<<endl;
//    }
//    auto enemy=world->getEnemies();
//    gameModel->setEnemies(enemy);
//    auto enemies_gamemodel=gameModel->getEnemies();
//    std::cout<<"enemies at location"<<std::endl;
//    for(auto &e:enemies_gamemodel){
//        cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
//        std::vector<std::shared_ptr<Tile>> healthPacks;
//    }


//    auto penemies_gamemodel=gameModel->getPEnemies();
//    std::cout<<"Penemies at location"<<std::endl;
//    for(auto &e:penemies_gamemodel){
//        cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
//        std::cout<<"Xenemies at location"<<std::endl;
//        cout<<'['<<e->getPEnemy()->getXPos() + rand() % 28+1 <<','<<e->getPEnemy()->getYPos() + rand() % 28+1<<']'<<endl;
//    }

//    auto enemies=world->getEnemies();
//    gameModel->setEnemies(enemies);
//    auto actual_enemies=gameModel->getEnemies();

//    //Test enemies
//    std::cout<<"enzmies at"<<endl;
//    for(auto &e:actual_enemies){
//        cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
//    }

//    //Test Penemies
//    auto actual_penemies= gameModel->getPEnemies();
//    std::cout<<"Penemies at"<<endl;
//    for(auto &e:actual_penemies){
//        cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
//    }

//    //Test Xenemies and set their positions

//    std::cout<<"Xenemies at"<<endl;
//    int xPos=0; int yPos=0;
//    XenemyModel setXenemies;
//    auto actual_xenemies= gameModel->getPEnemies();

//    for(auto &x_enemy:actual_xenemies){
//        cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
//        xPos = x_enemy->getPEnemy()->getXPos() + rand();
//        if(xPos > 30){
//            xPos = xPos - rand() % 25 + 1;
//        }
//        yPos = x_enemy->getPEnemy()->getYPos() + rand();
//        if (yPos > 30){
//            yPos = yPos - rand() % 25 + 1;
//        }
//        setXenemies.setXEnemy(xPos, yPos);
//    }

/*

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

            //Test HealthPack
            cout<<"Health pack at "<<endl;
            auto health=world->getHealthPacks();
            gameModel->setHealthPacks(health);
            auto actual_healthpack=gameModel->getHealthPacks();
            for(auto &h:actual_healthpack){
                cout<<'['<<h->getHealthPack()->getXPos()<<','<<h->getHealthPack()->getValue()<<']'<<endl;
            }
*/

//    for (auto &d :dummy ) {
//        for(int i=0;i<world->getCols();i++){
//                cout<<"|";
//                for(int y=0;y<world->getRows();y++){
//                    if(i==d.second && y==d.first){
//                        cout<<"p"<<" |";
//                    } else{
//                         cout<< tiles[i*world->getCols()+y]->getValue()<<" |";
//                    }
//                }
//                cout<<endl;
//            }

//        cout<<d.first<<d.second<<endl;
//    }


//            auto world_tiles=world->getTiles();
//            gameModel->setTiles(world_tiles);
//            auto gamemodel_tiles=gameModel->getTiles();
//            cout<<"Tiles at location"<<endl;
//            for(auto &e:gamemodel_tiles){
//                cout<<'['<<e->getTile()->getXPos()<<','<<e->getTile()->getYPos()<<"] "<<e->isObstacle()<<endl;
//            }
//       auto enemy=world->getEnemies();
//        gameModel->setEnemies(enemy);
//        auto enemies_gamemodel=gameModel->getEnemies();
//        std::cout<<"enemies at location"<<std::endl;
//        for(auto &e:enemies_gamemodel){
//              cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
//              std::vector<std::shared_ptr<Tile>> healthPacks;
//            }


//        auto penemies_gamemodel=gameModel->getPEnemies();
//        std::cout<<"Penemies at location"<<std::endl;
//        for(auto &e:penemies_gamemodel){
//              cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
//            }

//            auto enemies=world->getEnemies();
//            gameModel->setEnemies(enemies);
//            auto actual_enemies=gameModel->getEnemies();

//            //Test enemies
//            std::cout<<"enzmies at"<<endl;
//            for(auto &e:actual_enemies){
//                cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
//            }

//            //Test Penemies
//            auto actual_penemies= gameModel->getPEnemies();
//            std::cout<<"Penemies at"<<endl;
//            for(auto &e:actual_penemies){
//                cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
//            }

//        //Test Xenemies and set their positions

//            std::cout<<"Xenemies at"<<endl;
//            int xPos=0; int yPos=0;
//            XenemyModel setXenemies;
//            auto actual_xenemies= gameModel->getPEnemies();

//            for(auto &x_enemy:actual_xenemies){
//                cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
//                xPos = x_enemy->getPEnemy()->getXPos() + rand();
//                if(xPos > 30){
//                    xPos = xPos - rand() % 25 + 1;
//                }
//                yPos = x_enemy->getPEnemy()->getYPos() + rand();
//                if (yPos > 30){
//                    yPos = yPos - rand() % 25 + 1;
//                }
//                setXenemies.setXEnemy(xPos, yPos);
//                }

///*

//            auto protagonist=world->getProtagonist();
//            auto protagonist_model=make_shared<protagonistModel>();
//            protagonist_model->setProtagonist(protagonist);
//            auto protagonist_gamemodel = protagonist_model->getProtagonist();
//            gameModel->setProtagonist(protagonist_model);
//            auto actual_protagonist=gameModel->getProtagonist();

//            std::cout<< "protagonist at ["<<actual_protagonist->getProtagonist()->getXPos()<<", "<< actual_protagonist->getProtagonist()->getYPos()<<"]"<<std::endl;
//            actual_protagonist->getProtagonist()->setHealth(98.0);

//            //TEST PROTAGONIST MODEL


//            actual_protagonist->moveRight();
//            actual_protagonist->moveRight();
//            actual_protagonist->moveRight();
//            actual_protagonist->moveLeft();
//            actual_protagonist->moveUp();
//            actual_protagonist->moveUp();
//            actual_protagonist->moveDown();
//            std::cout<< "protagonist move to position ["<<actual_protagonist->getProtagonist()->getXPos()<<", "<< actual_protagonist->getProtagonist()->getYPos()<<"]"<<std::endl;
//            std::cout<<"Protagonist has "<<actual_protagonist->getProtagonist()->getHealth()<<" health"<<std::endl;
//            protagonist_model->decreaseHealth(15.6);
//            std::cout<<"Protagonist has been attacked new health is "<<actual_protagonist->getProtagonist()->getHealth()<<std::endl;
//            std::cout<<"Protagonist has "<<actual_protagonist->getProtagonist()->getEnergy()<<" energy"<<std::endl;
//            protagonist_model->decreaseEnergy(0.9);
//            std::cout<<"Protagonist lost energy new energy is "<<actual_protagonist->getProtagonist()->getEnergy()<<std::endl;

//            //Test HealthPack
//            cout<<"Health pack at "<<endl;
//            auto health=world->getHealthPacks();
//            gameModel->setHealthPacks(health);
//            auto actual_healthpack=gameModel->getHealthPacks();
//            for(auto &h:actual_healthpack){
//                cout<<'['<<h->getHealthPack()->getXPos()<<','<<h->getHealthPack()->getYPos()<<']'<<endl;
//            }*/



}

MainWindow::~MainWindow()
{
    delete ui;
}

