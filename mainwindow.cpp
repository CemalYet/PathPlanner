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
    setMouseTracking(true);
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(zoomout()));

    auto world = make_shared<World>();
    world->createWorld(":/images/maze3",1,1);
    gameModel = std::make_shared<GameModel>();
    gameModel->setCols(world->getCols());
    gameModel->setRows(world->getRows());


    auto world_tiles=world->getTiles();
    gameModel->setTiles(world_tiles);
    auto gamemodel_tiles=gameModel->getTiles();

    auto enemy=world->getEnemies();
    gameModel->setEnemies(enemy);

    auto enemies=world->getEnemies();
    gameModel->setEnemies(enemies);

    auto penemies_gamemodel=gameModel->getPEnemies();


    auto protagonist=world->getProtagonist();
    auto protagonist_model=make_shared<protagonistModel>();
    protagonist_model->setProtagonist(protagonist);
    auto protagonist_gamemodel = protagonist_model->getProtagonist();
    gameModel->setProtagonist(protagonist_model);

    auto health=world->getHealthPacks();
    gameModel->setHealthPacks(health);

    gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getEnergy());
    ui->energy->setValue(gameModel->getProtagonist()->getProtagonist()->getEnergy());

    gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getHealth());
    ui->health->setValue(gameModel->getProtagonist()->getProtagonist()->getHealth());

    path =make_shared<PathPlanner>(gameModel,1);
    //pair<float,vector<pair<int,int>>> dummy=path->solution1(1200,1205);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_radioButton_clicked()
{
    graphicView = std::make_shared<ViewGraphical>(gameModel->getRows(),gameModel->getCols());
    scene = graphicView->getScene();
    auto nrOfCols = gameModel->getCols();
    auto nrOfRows = gameModel->getRows();
    scene->setSceneRect(0,0,nrOfCols,nrOfRows);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/maze3")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(nrOfCols,nrOfRows);



//-----------------------------------------------------------------------------------------------
//----------------------  Protagonist   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------
            viewProtagonist = new ViewProtagonist();
            //viewProtagonist->setRect(0,0,90,90);
            viewProtagonist->setPixmap(QPixmap(":/images/scorpion_4.png"));
            viewProtagonist->setFlag(QGraphicsItem::ItemIsFocusable);
            viewProtagonist->setFocus();
            scene->addItem(viewProtagonist);

            //scene->addLine(QLineF(200, 300, 100, 150));

//-----------------------------------------------------------------------------------------------
//----------------------  Penemies  ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------
            auto actual_penemies= gameModel->getPEnemies();
            viewPenemy = new ViewPenemy();
            viewPenemy->setPixmap(QPixmap(":/images/Raiden.png"));
            for(auto &e:actual_penemies){
                cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
                //viewPenemy->setPos(e->getPEnemy()->getXPos() + 100, e->getPEnemy()->getYPos() + 100);  //line below for test to set the penemy closer
                viewPenemy->setPos(50,50);
            }
            scene->addItem(viewPenemy);

//-----------------------------------------------------------------------------------------------
//----------------------  Xenemies   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------
            auto actual_xenemies= gameModel->getPEnemies();
            xenemy = new XenemyModel();
            int xPos=0; int yPos=0;
            for(auto &x_enemy:actual_xenemies){
                //cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
                xPos = x_enemy->getPEnemy()->getXPos() + rand() % 1000;
                if(xPos > 2200){
                    xPos = xPos - rand() % 25 + 1;
                }
                yPos = x_enemy->getPEnemy()->getYPos() + rand() % 1000;
                if (yPos > 2200){
                    yPos = yPos - rand() % 25 + 1;
                }
                std::cout<<"Xenemies at"<<endl;
                std::cout<<xPos<<","<<yPos<<endl;
             }
            //xenemy->setPos(xPos, yPos);   //this line should be used but i'm using the one below just to check the functionality easier
            xenemy->setPos(0, 100);
            scene->addItem(xenemy);
            //show();
//-----------------------------------------------------------------------------------------------
//----------------------  Health packs   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------

            cout<<"Health pack at "<<endl;

            auto actual_healthpack=gameModel->getHealthPacks();

            healtPack = new ViewHealthPack();
            healtPack->setPixmap(QPixmap(":/images/healthpack.png"));
            for(auto &h:actual_healthpack){
                //cout<<'['<<h->getHealthPack()->getXPos()<<','<<h->getHealthPack()->getYPos()<<']'<<endl;
                //healtPack->setPos(h->getHealthPack()->getXPos(), h->getHealthPack()->getYPos()); //this line should be used but i'm using the one below just to check the functionality easier
                healtPack->setPos(0, 150);
            }
            scene->addItem(healtPack);

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    auto protagonistCurrentXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistCurrentYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();

    qDebug() << "the x value in mainwindow: " << protagonistCurrentXPos << "the y value in mainwindow:" << protagonistCurrentYPos;

    if(event->key() == Qt::Key_K){
        auto tileAtLeftPos=gameModel->getTileAtAPos(protagonistCurrentXPos-1,protagonistCurrentYPos);
            //if (pos().x() > 0)  {  //make sure that protagonist doesn't pass the frame while moving left
            if((!(tileAtLeftPos->isObstacle())) && (protagonistCurrentXPos > 0)) {
            gameModel->getProtagonist()->moveLeft();
            viewProtagonist->moveLeft(protagonistCurrentXPos, protagonistCurrentYPos, gameModel);
            updateHealth(gameModel->getProtagonist()->getProtagonist()->getHealth());
            updateEnergy(gameModel->getProtagonist()->getProtagonist()->getEnergy());
            //scene->addLine(QLineF(protagonistCurrentXPos, protagonistCurrentYPos, protagonistCurrentXPos+1, protagonistCurrentYPos));
            }
        }
        else if (event->key() == Qt::Key_M){
        auto tileAtRightPos=gameModel->getTileAtAPos(protagonistCurrentXPos+1,protagonistCurrentYPos);
            if(!(tileAtRightPos->isObstacle())) {
                //qDebug() << "Trying to move to the right and it's not blocked!";
                //update the model
                gameModel->getProtagonist()->moveRight();
                //update the view
                viewProtagonist->moveRight(protagonistCurrentXPos, protagonistCurrentYPos, gameModel);
                auto dummy = path->solution1(10,10);
                for(unsigned long i=0; 14<i ; i++){
                    qDebug() << "inside for loop for pathplanner";
                    scene->addLine(QLineF(dummy.second[i].first, dummy.second[i].second, dummy.second[i+1].first, dummy.second[i+1].second));
                }
                updateHealth(gameModel->getProtagonist()->getProtagonist()->getHealth());
                updateEnergy(gameModel->getProtagonist()->getProtagonist()->getEnergy());
                cout<< dummy.second.size()<<"size"<<endl;
            }
        }
        else if (event->key() == Qt::Key_O){
            auto tileAtUpPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos-1);
            //if (pos().y() > 0){
            if(!(tileAtUpPos->isObstacle())){
                gameModel->getProtagonist()->moveUp();
                viewProtagonist->moveUp(protagonistCurrentXPos, protagonistCurrentYPos, gameModel);
                updateHealth(gameModel->getProtagonist()->getProtagonist()->getHealth());
                updateEnergy(gameModel->getProtagonist()->getProtagonist()->getEnergy());
            }
        }
        else if (event->key() == Qt::Key_L){
            auto tileAtDownPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos+1);
            //if (pos().y() + 100 < 600){
            if(!(tileAtDownPos->isObstacle())) {
                gameModel->getProtagonist()->moveDown();
                viewProtagonist->moveDown(protagonistCurrentXPos, protagonistCurrentYPos, gameModel);
                updateHealth(gameModel->getProtagonist()->getProtagonist()->getHealth());
                updateEnergy(gameModel->getProtagonist()->getProtagonist()->getEnergy());
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


void MainWindow::mouseMoveEvent(QMouseEvent *event){
    qDebug() << event->pos();

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


void MainWindow::updateHealth(float value)
{
     std::cout<<"health"<<gameModel->getProtagonist()->getProtagonist()->getHealth()<<std::endl;
     ui->health->setValue(value);
}


//void MainWindow::MainWindow::paintEvent(QPaintEvent *event)
//{
//    QPainterPath path;

//    //    path.lineTo(10,250);
//    //    path.lineTo(20,300);

//        QPainter painter(this);
//        painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
//                            Qt::FlatCap, Qt::MiterJoin));
//        painter.setBrush(QColor(122, 163, 39));

//        for(int i =0;i<30;i++){
//            path.addRect(i+5,i+3,i+10,i+13);
//            painter.drawPath(path);
//        }


//        painter.drawPath(path);
//}



void MainWindow::updateEnergy(float value){
    std::cout<<"energy"<<gameModel->getProtagonist()->getProtagonist()->getEnergy()<<std::endl;
    ui->energy->setValue(value);

}


