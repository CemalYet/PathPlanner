#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world_global.h"
#include "world.h"
#include "node.h"
#include "protagonistModel.h"
#include "PenemyModel.h"
#include "enemyModel.h"
#include "ViewTile.h"
#include "pathplanner.h"
#include "XenemyModel.h"
#include "TileModel.h"
#include "gameModel.h"
#include "arrowtextcommand.h"
#include "gototextcommand.h"
#include "helptextcommand.h"
#include "nearestenemycommand.h"
#include "nearesthealthpackcommand.h"
#include <qdebug.h>
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
#include "ViewGraphical.h"
#include <QPainterPath>
#include <QPainter>
#include <sstream>
#include "pathplanner.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    //connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(zoomout()));
    //ui->zoom_group->hide();


    auto world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",10,10);
    gameModel = std::make_shared<GameModel>();
    gameModel->setCols(world->getCols());
    gameModel->setRows(world->getRows());


    auto world_tiles=world->getTiles();
    gameModel->setTiles(world_tiles);
    auto gamemodel_tiles=gameModel->getTiles();

    auto enemy=world->getEnemies();
    cout<<"size of enemies directlr is"<< enemy.size() <<endl;
    gameModel->setEnemies(enemy);

    auto penemies_gamemodel=gameModel->getPEnemies();
    auto enemies_gamemodel = gameModel->getEnemies();

    gameModel->setXEnemies();
    auto xenemies = gameModel->getXEnemies();

    auto protagonist=world->getProtagonist();
    auto protagonist_model=make_shared<protagonistModel>();
    protagonist_model->setProtagonist(protagonist);
    auto protagonist_gamemodel = protagonist_model->getProtagonist();
    gameModel->setProtagonist(protagonist_model);
    //gameModel->getProtagonist()->getProtagonist()->setXPos(0);
    //gameModel->getProtagonist()->getProtagonist()->setYPos(45);

    auto health=world->getHealthPacks();
    gameModel->setHealthPacks(health);

    gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getEnergy());
    ui->energy->setValue(gameModel->getProtagonist()->getProtagonist()->getEnergy());

    gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getHealth());
    ui->health->setValue(gameModel->getProtagonist()->getProtagonist()->getHealth());

    path =make_shared<PathPlanner>(gameModel,1);
    auto autoPlay=path->autoPlay();
    if(autoPlay.first){
        cout<<"you win "<<endl;
        cout<<autoPlay.second.size()<<endl;
    }else{
        cout<<"game over"<<endl;
        cout<<autoPlay.second.size()<<endl;
    }

    //get text scene
    gameTextView =std::make_shared<ViewText>(gameModel->getRows(),gameModel->getCols());
    scene = gameTextView->getScene();
    for (auto &tile: gamemodel_tiles){
        auto XPosTile=tile->getTile()->getXPos();
        auto YPosTile=tile->getTile()->getYPos();
        auto valueTile=tile->getTile()->getValue();
        auto tileType=gameModel->getTileType(XPosTile,YPosTile);
        gameTextView->setTextTileView(XPosTile,YPosTile,valueTile,tileType);
    }
    createTextCommandToClassMap();

    //get graphical scene
    graphicView = std::make_shared<ViewGraphical>(gameModel->getRows(),gameModel->getCols());
    scene_graphics = graphicView->getScene();
    auto nrOfCols = gameModel->getCols();
    auto nrOfRows = gameModel->getRows();
    scene_graphics->setSceneRect(0,0,nrOfCols,nrOfRows);


//    for(auto &e:penemies_gamemodel){
//           viewPenemy = new ViewPenemy(0, e->getPEnemy()->getXPos(), e->getPEnemy()->getYPos());
//           scene_graphics->addItem(viewPenemy);
//           qDebug() << "Penemmy is added";
//           show();
//       }

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    int goalX=ev->position().x()-40;
    int goalY=ev->position().y()-61;

    qDebug()<<" Mouse is clicked at: x="<< goalX << "and at y="<< goalY;
    auto dummy = path->solution1(999,938);  //I subtracted these values so that my initial cordination start from the corner up left of qgraphicsview window
    int index=0;
    QGraphicsLineItem *line;
    QPen pen(Qt::red);
    pen.setWidth(10);
    for(auto & ab : dummy.second){
        //qDebug() << "inside for loop, ab.first is"<< ab.first << "ab.second is"<< ab.second;
        line = scene_graphics->addLine(QLineF(ab.first, ab.second, dummy.second[index + 1].first, dummy.second[index + 1].second), pen);
        line->setVisible(true);
        qDebug() << ab.first << ab.second << dummy.second[index + 1].first << dummy.second[index + 1].second;
        index++;
    }
    line->setVisible(false);

    //update the protagonist model position
    gameModel->getProtagonist()->goTo(999,938);

    //update the view position for the protagonist
    viewProtagonist->setPosition(999,938);

    qDebug() <<"protagonist x position is :" << gameModel->getProtagonist()->getProtagonist()->getXPos() << "protagonist y position is :" << gameModel->getProtagonist()->getProtagonist()->getYPos();
}

void MainWindow::on_radioButton_graphics_clicked()
{
    //ui->zoom_group->show();
    scene->clear();
    ui->graphicsView->setScene(scene_graphics);
    scene_graphics->addPixmap(QPixmap(":/images/worldmap.jpg"));


    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setFixedSize(nrOfCols,nrOfRows);



//-----------------------------------------------------------------------------------------------
//----------------------  Protagonist   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------
    auto protagonistXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    viewProtagonist = new ViewProtagonist(0, protagonistXPos, protagonistYPos);
    scene_graphics->addItem(viewProtagonist);


//-----------------------------------------------------------------------------------------------
//----------------------  Penemies  ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------
    auto actual_penemies= gameModel->getPEnemies();


    for(auto &e:actual_penemies){
        viewPenemy = new ViewPenemy(0, e->getPEnemy()->getXPos(), e->getPEnemy()->getYPos());
        scene_graphics->addItem(viewPenemy);
    }
    scene_graphics->addItem(viewPenemy);
//    scene_graphics->update();

//-----------------------------------------------------------------------------------------------
//----------------------  Xenemies   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------

    auto actual_xenemies=gameModel->getXEnemies();

    for(auto &e:actual_xenemies){
        //cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
        //viewPenemy->setPos(e->getPEnemy()->getXPos() + 100, e->getPEnemy()->getYPos() + 100);  //line below for test to set the penemy closer
        auto xEnemyXPos = e->getXPosition();
        auto xEnemyYPos = e->getYPosition();
        xenemy = new ViewXenemy(0, xEnemyXPos, xEnemyYPos);


        //viewPenemy->setPos(xEnemyXPos, xEnemyYPos);

        scene_graphics->addItem(xenemy);
    }
//-----------------------------------------------------------------------------------------------
//----------------------  Health packs   ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------
            //cout<<"Health pack at "<<endl;
            auto actual_healthpack=gameModel->getHealthPacks();

            //healtPack->setPixmap(QPixmap(":/images/healthpack.png"));
            for(auto &h:actual_healthpack){
                //cout<<'['<<h->getHealthPack()->getXPos()<<','<<h->getHealthPack()->getYPos()<<']'<<endl;
                healtPack = new ViewHealthPack(0, h->getHealthPack()->getXPos(), h->getHealthPack()->getYPos());
                //healtPack->setPos(0, 150);
                scene_graphics->addItem(healtPack);
            }
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

                //-----------------------------------------------------------------------------------------------------------------------
                //this is a test, it should belong to mouse click event and NOT HERE!
                auto dummy = path->solution1(10,10);
                for(unsigned long i=0; 14<i ; i++){
                    qDebug() << "inside for loop for pathplanner";
                    scene_graphics->addLine(QLineF(dummy.second[i].first, dummy.second[i].second, dummy.second[i+1].first, dummy.second[i+1].second));
                }

                //-----------------------------------------------------------------------------------------------------------------------
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
}


//void MainWindow::mouseMoveEvent(QMouseEvent *event){
//    qDebug() << event->pos();

//}


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

void MainWindow::on_radioButton_Text_clicked()
{
    scene_graphics->clear();
    ui->graphicsView->setScene(scene);

    auto protagonistXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    auto tv=gameTextView->buildPartialView(protagonistXPos,protagonistYPos);
    textViewItem=scene->addText(tv);

}

void MainWindow::processTextCommand(QString userCommand)
{

    QStringList CommandList = userCommand.split(" ");
    std::string command=CommandList[0].toStdString();
    std::list<std::string> joinedString = {};
    for( int i=1; i<CommandList.count(); ++i ){
        std::string commandtail=CommandList[i].toStdString();
        joinedString.push_back(commandtail);
    }
   if(textCommandToClassMap[command]){
       textCommandToClassMap[command]->execute(command,joinedString);
         std::cout<<"no problem"<<std::endl;
     }
}

void MainWindow::createTextCommandToClassMap()
{

    auto commandObject =  std::make_shared<ArrowTextCommand>(gameModel,gameTextView);
    textCommandToClassMap["right"]=commandObject;
    textCommandToClassMap["left"]=commandObject;
    textCommandToClassMap["up"]=commandObject;
    textCommandToClassMap["down"]=commandObject;

    auto gotoObject=std::make_shared<GoToTextCommand>(gameModel,gameTextView);
    textCommandToClassMap["goto"]=gotoObject;

    textCommandToClassMap["help"]=std::make_shared<HelpTextCommand>(gameModel,gameTextView,ui->helpResponse);

    auto nearestEnemyCommandObject=std::make_shared<NearestEnemyCommand>(gameModel,gameTextView);
    textCommandToClassMap["enemy"]=nearestEnemyCommandObject;

    auto nearestHealthCommandObject=std::make_shared<NearestHealthPackCommand>(gameModel,gameTextView);
    textCommandToClassMap["health"]=nearestHealthCommandObject;

    QObject::connect(nearestHealthCommandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
    QObject::connect(nearestHealthCommandObject.get(),SIGNAL(updateMainWindowView(QString)),this,SLOT(updateMainWindowViewSlot(QString)));

    QObject::connect(nearestEnemyCommandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
    QObject::connect(nearestEnemyCommandObject.get(),SIGNAL(updateMainWindowView(QString)),this,SLOT(updateMainWindowViewSlot(QString)));

    QObject::connect(commandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));

    QObject::connect(gotoObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
    QObject::connect(gotoObject.get(),SIGNAL(updateMainWindowView(QString)),this,SLOT(updateMainWindowViewSlot(QString)));

}


void MainWindow::on_executeButton_clicked()
{
    ui->helpResponse->clear();
    QString inputCommand=ui->userInput->toPlainText();
    processTextCommand(inputCommand.toLower());
    scene->removeItem(textViewItem);
    auto protagonistXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    textViewItem=scene->addText(gameTextView->buildPartialView(protagonistXPos,protagonistYPos));
    updateEnergy(gameModel->getProtagonist()->getProtagonist()->getEnergy());
    updateHealth(gameModel->getProtagonist()->getProtagonist()->getHealth());
    QString protagonistPos="Protagonist("%QString::number(protagonistXPos)%","%QString::number(protagonistYPos)%")";//added
    ui->textBrowser->setText(protagonistPos);//added
}

void MainWindow::updateEnergy(float value){
    ui->energy->setValue(value);
}

void MainWindow::updateHealth(float value)
{
    // std::cout<<"health"<<gameModel->getProtagonist()->getProtagonist()->getHealth()<<std::endl;
     ui->health->setValue(value);
}

void MainWindow::gameOverSlot(const QString &message)
{
    ui->textBrowser->setStyleSheet("background-color: red;");
    ui->textBrowser->setText(message);
    ui->executeButton->setEnabled(false);
}

void MainWindow::updateMainWindowViewSlot(QString buildview)
{

    scene->removeItem(textViewItem);
    textViewItem=scene->addText(buildview);
    //show protagonist position as well
    auto protagonist=gameModel->getProtagonist()->getProtagonist();
    QString xpos=QString::number(protagonist->getXPos());
    QString ypos=QString::number(protagonist->getYPos());
    QString protagonistPosition="Protagonist("%xpos%","%ypos%")";
    ui->textBrowser->setText(protagonistPosition);
    updateEnergy(protagonist->getEnergy());
    updateHealth(protagonist->getHealth());
}



/*void MainWindow::on_comboBox_activated(int index)
{
    //world = make_shared<World>();
    switch(index){
    case 1:
        world->createWorld(":/images/worldmap.jpg",10,5);
        std::cout<<" case1"<<std::endl;
        break;
    case 2:
        world->createWorld(":/images/worldmap4.jpg",10,5);
        std::cout<<" case2"<<std::endl;
       break;
    case 3:
       //world->createWorld(":/images/maze1.jpg",5,5);
       std::cout<<" case3"<<std::endl;
       break;
    case 4:
       // world->createWorld(":/images/maze2.jpg",0,0);
        std::cout<<" case4"<<std::endl;
       break;
    case 5:
        //world->createWorld(":/images/maze3.jpg",0,0);
        std::cout<<" case5"<<std::endl;
       break;
    }
}*/


