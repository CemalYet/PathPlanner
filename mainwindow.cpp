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
#include <qdebug.h>
#include <vector>
#include <memory>
<<<<<<< mainwindow.cpp
#include <sstream>
#include "pathplanner.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QObject::connect(ui->comboBox,qOverload<int>(&QComboBox::activated),this,&MainWindow::selectWorld);
    // QObject::connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(selectWorld(int)));
    //QObject::connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(on_comboBox_activated(int)));

/// (0,22) -> (1200,1205); maze3
/// (0,45) -> (999, 938)


    world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",10,10);
    gameModel = std::make_shared<GameModel>();

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


     pair<float,vector<pair<int,int>>> dummy=pathPlanner->solution1(1200,1205);



//initialize protagonist in gamemodel
            auto protagonist=world->getProtagonist();

            auto protagonist_model=make_shared<protagonistModel>();
            protagonist_model->setProtagonist(protagonist);
            auto protagonist_gamemodel = protagonist_model->getProtagonist();
            gameModel->setProtagonist(protagonist_model);

            //gameModel->getProtagonist()->getProtagonist()->setPos(0,22);



//initialize health and energy in both model and view
            gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getEnergy());
            ui->energy->setValue(gameModel->getProtagonist()->getProtagonist()->getEnergy());

            gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getHealth());
            ui->health->setValue(gameModel->getProtagonist()->getProtagonist()->getHealth());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_radioButton_Text_clicked()
{

    gameTextView =std::make_shared<ViewText>(gameModel->getRows(),gameModel->getCols());
    scene = gameTextView->getScene();
    //scene->setSceneRect(0,0,1920,1080);
    ui->graphicsView->setScene(scene);


    for (auto &tile: gameModel->getTiles()){

        auto XPosTile=tile->getTile()->getXPos();
        auto YPosTile=tile->getTile()->getYPos();
        auto valueTile=tile->getTile()->getValue();
        auto tileType=gameModel->getTileType(XPosTile,YPosTile);
        gameTextView->setTextTileView(XPosTile,YPosTile,valueTile,tileType);
    }

    auto protagonistXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    auto tv=gameTextView->buildPartialView(protagonistXPos,protagonistYPos);
    textViewItem=scene->addText(tv);
    createTextCommandToClassMap();
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
    QObject::connect(nearestEnemyCommandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
    QObject::connect(commandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
    QObject::connect(gotoObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
    QObject::connect(gotoObject.get(),SIGNAL(updateMainWindowView(QString)),this,SLOT(updateMainWindowViewSlot(QString)));
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

    //gameTextView->printTileViewVectors();

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

void MainWindow::selectWorld(int index){
    world = make_shared<World>();
    switch(index){
    case 1:
        world->createWorld(":/images/worldmap.jpg",10,5);
        break;
    case 2:
        world->createWorld(":/images/worldmap4.jpg",10,5);
       break;
    case 3:
       world->createWorld(":/images/maze1.jpg",5,5);
       break;
    case 4:
        world->createWorld(":/images/maze2.jpg",0,0);
       break;
    case 5:
        world->createWorld(":/images/maze3.jpg",0,0);
       break;
    }
}

