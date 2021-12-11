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
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QImage>
#include <QBrush>
#include <QFont>
#include <QGraphicsScene>
#include <QApplication>
#include "ViewPenemy.h"
#include "Projectile.h"
#include "TileModel.h"
#include <QList>
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QImage>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(zoomout()));

    auto world = make_shared<World>();
    world->createWorld(":/images/maze3.jpg",1,1);
    gameModel = std::make_shared<GameModel>();
    gameModel->setCols(world->getCols());
    gameModel->setRows(world->getRows());

    //auto pathPlanner=make_shared<PathPlanner>(world,0.2);
    //vector<pair<int,int>> dummy=pathPlanner->solution(4,4);
    //auto tiles=pathPlanner->getGameBoard();


//    cout<<"PATH === "<<dummy.size()<<endl;

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
            auto world_tiles=world->getTiles();
            gameModel->setTiles(world_tiles);
            auto gamemodel_tiles=gameModel->getTiles();
            cout<<"Tiles at location"<<endl;
//            for(auto &e:gamemodel_tiles){
//                //cout<<'['<<e->getTile()->getXPos()<<','<<e->getTile()->getYPos()<<"] "<<e->isObstacle()<<endl;
//            }
       auto enemy=world->getEnemies();
        gameModel->setEnemies(enemy);
        auto enemies_gamemodel=gameModel->getEnemies();
        std::cout<<"enemies at location"<<std::endl;
//        for(auto &e:enemies_gamemodel){
//              //cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
//              std::vector<std::shared_ptr<Tile>> healthPacks;
//            }




        auto penemies_gamemodel=gameModel->getPEnemies();
        std::cout<<"Penemies at location"<<std::endl;
//        for(auto &e:penemies_gamemodel){
//              cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
//            }

            auto enemies=world->getEnemies();
            gameModel->setEnemies(enemies);
            auto actual_enemies=gameModel->getEnemies();

//            //Test enemies
//            std::cout<<"enzmies at"<<endl;
//            for(auto &e:actual_enemies){
//                //cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
//            }

            //Test Penemies
            auto actual_penemies= gameModel->getPEnemies();


        //Test Xenemies and set their positions
            auto actual_xenemies= gameModel->getPEnemies();


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

            }*/

            //-------------------------------------------------------------------------------------
            scene = new QGraphicsScene();
            auto nrOfCols = gameModel->getCols();
            auto nrOfRows = gameModel->getRows();
            scene->setSceneRect(0,0,nrOfCols,nrOfRows);
            ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/maze3")));
            //QImage world_boo = QImage(900, 900,monostate);
            //QImage myImage;
            //myImage=QImage(":/images/worldmap");
           // myImage.load(":/images/worldmap");
            //ui->graphicsView->setBackgroundBrush(QBrush(QImage(const QSize &size, Format format)));
            //viewGraphical->setScene(scene);
            ui->graphicsView->setScene(scene);
            ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            //ui->graphicsView->setFixedSize(1500,1500);
//-----------------------------------------------------------------------------------------------
//----------------------  Protagonist   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------

//update the model

            auto protagonist=world->getProtagonist();
            auto protagonist_model=make_shared<protagonistModel>();
            protagonist_model->setProtagonist(protagonist);
            auto protagonist_gamemodel = protagonist_model->getProtagonist();
            gameModel->setProtagonist(protagonist_model);
            auto actual_protagonist=gameModel->getProtagonist();

            std::cout<< "protagonist at ["<<actual_protagonist->getProtagonist()->getXPos()<<", "<< actual_protagonist->getProtagonist()->getYPos()<<"]"<<std::endl;
            actual_protagonist->getProtagonist()->setHealth(98.0);

//update the view
            viewProtagonist = new ViewProtagonist();
            //viewProtagonist->setRect(0,0,90,90);
            viewProtagonist->setPixmap(QPixmap(":/images/scorpion_4.png"));
            viewProtagonist->setFlag(QGraphicsItem::ItemIsFocusable);
            viewProtagonist->setFocus();
            scene->addItem(viewProtagonist);
//------------------------------------------------------------------------------------------------------
//            viewHealth = new ViewHealth();
//            scene->addItem(viewHealth);
//            viewHealth->setPos(viewHealth->x()+90,viewHealth->y()+25);


            viewPenemy = new ViewPenemy();
            viewPenemy->setPixmap(QPixmap(":/images/Raiden.png"));
            for(auto &e:actual_penemies){
                //cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
                viewPenemy->setPos(e->getPEnemy()->getXPos() + 100, e->getPEnemy()->getYPos() + 100);
            }
            scene->addItem(viewPenemy);

//-------------------------------------------------------------------------------------------------------
            viewXenemy = new ViewXenemy();
            viewXenemy->setPixmap(QPixmap(":/images/sindel.png"));
            int xPos=0; int yPos=0;
            for(auto &x_enemy:actual_xenemies){
                //cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
                xPos = x_enemy->getPEnemy()->getXPos() + rand() % 1500;
                if(xPos > 30){
                    xPos = xPos - rand() % 25 + 1;
                }
                yPos = x_enemy->getPEnemy()->getYPos() + rand() % 2000;
                if (yPos > 30){
                    yPos = yPos - rand() % 25 + 1;
                }
                viewXenemy->setPos(xPos, yPos);
                std::cout<<"Xenemies at"<<endl;
                std::cout<<xPos<<","<<yPos<<endl;
             }
            scene->addItem(viewXenemy);

//-------------------------------------------------------------
            xenemy = new XenemyModel();
            for(auto &x_enemy:actual_xenemies){
                //cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
                xPos = x_enemy->getPEnemy()->getXPos() + rand() % 1500;
                if(xPos > 30){
                    xPos = xPos - rand() % 25 + 1;
                }
                yPos = x_enemy->getPEnemy()->getYPos() + rand() % 1500;
                if (yPos > 30){
                    yPos = yPos - rand() % 25 + 1;
                }
                viewXenemy->setPos(xPos, yPos);
                std::cout<<"Xenemies at"<<endl;
                std::cout<<xPos<<","<<yPos<<endl;
             }
            xenemy->setPos(xPos, yPos);
            scene->addItem(xenemy);
            //show();
//----------------------------------------------------------------------
//set health pack
//----------------------------------------------------------------------

            cout<<"Health pack at "<<endl;
            auto health=world->getHealthPacks();
            gameModel->setHealthPacks(health);
            auto actual_healthpack=gameModel->getHealthPacks();

            healtPack = new ViewHealthPack();
            healtPack->setPixmap(QPixmap(":/images/healthpack.png"));
            for(auto &h:actual_healthpack){
                //cout<<'['<<h->getHealthPack()->getXPos()<<','<<h->getHealthPack()->getYPos()<<']'<<endl;
                healtPack->setPos(h->getHealthPack()->getXPos(), h->getHealthPack()->getYPos());
            }
            scene->addItem(healtPack);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    auto protagonistCurrentXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistCurrentYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    qDebug() << "the x value in mainwindow: " << protagonistCurrentXPos << "the y value in mainwindow:" << protagonistCurrentYPos;

    if(event->key() == Qt::Key_K){
        auto tileAtLeftPos=gameModel->getTileAtAPos(protagonistCurrentXPos-1,protagonistCurrentYPos);
            //if (pos().x() > 0)  {  //make sure that protagonist doesn't pass the frame while moving left
            if(!(tileAtLeftPos->isObstacle())) {
            gameModel->getProtagonist()->moveLeft();
            viewProtagonist->moveLeft(protagonistCurrentXPos, protagonistCurrentYPos);
            }
        }
        else if (event->key() == Qt::Key_M){
        auto tileAtRightPos=gameModel->getTileAtAPos(protagonistCurrentXPos+1,protagonistCurrentYPos);
            if(!(tileAtRightPos->isObstacle())) {
                //qDebug() << "Trying to move to the right and it's not blocked!";
                //update the model
                gameModel->getProtagonist()->moveRight();
                //update the view
                viewProtagonist->moveRight(protagonistCurrentXPos, protagonistCurrentYPos);
            }
        }
        else if (event->key() == Qt::Key_O){
            auto tileAtUpPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos-1);
            //if (pos().y() > 0){
            if(!(tileAtUpPos->isObstacle())){
                gameModel->getProtagonist()->moveUp();
                viewProtagonist->moveUp(protagonistCurrentXPos, protagonistCurrentYPos);
            }
        }
        else if (event->key() == Qt::Key_L){
            auto tileAtDownPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos+1);
            //if (pos().y() + 100 < 600){
            if(!(tileAtDownPos->isObstacle())) {
                gameModel->getProtagonist()->moveDown();
                viewProtagonist->moveDown(protagonistCurrentXPos, protagonistCurrentYPos);
            }
        }
//        else if (event->key() == Qt::Key_D){
//                // create a bullet
//                Projectile * projectile = new Projectile();
//                projectile->setPos(x(),y());
//                scene->addItem(projectile);
//            }
//        else if (event->key() == Qt::Key_Z){
//                // create a bullet
//                Projectile * projectile = new Projectile(5);
//                projectile->setPos(x(),y());
//                scene->addItem(projectile);
//            }
//        else if (event->key() == Qt::Key_S){
//                // create a bullet
//                Projectile * projectile = new Projectile(5,6);
//                projectile->setPos(x(),y());
//                scene->addItem(projectile);
//            }
//        else if (event->key() == Qt::Key_Q){
//                // create a bullet
//                Projectile * projectile = new Projectile(5,6,6);
//                projectile->setPos(x(),y());
//                scene->addItem(projectile);
//            }
}



void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(1.1,1.1);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->graphicsView->scale(0.9,0.9);
}


void MainWindow::on_health_valueChanged(float value)
{
    QHBoxLayout *layout = new QHBoxLayout();

    std::cout<<"health"<<gameModel->getProtagonist()->getProtagonist()->getHealth()<<std::endl;
    ui->health->setValue(value);

    layout->addWidget(viewHealth);
    setLayout(layout);

}

