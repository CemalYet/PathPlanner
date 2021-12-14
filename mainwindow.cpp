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
#include <qdebug.h>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QObject::connect(ui->comboBox,qOverload<int>(&QComboBox::activated),this,&MainWindow::selectWorld);
    // QObject::connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(selectWorld(int)));
    //QObject::connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(on_comboBox_activated(int)));



    world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",10,5);
    gameModel = std::make_shared<GameModel>();



//initialize tiles in gamemodel
    auto world_tiles=world->getTiles();
    gameModel->setTiles(world_tiles);

//initialize row and coloum of tile board in gamemodel
            auto row=world->getRows();
            auto col=world->getCols();


            gameModel->setRows(row);
            gameModel->setCols(col);


//initialize enemies in gamemodel

        auto enemy=world->getEnemies();
        gameModel->setEnemies(enemy);
        auto penemies_gamemodel=gameModel->getPEnemies();

//initialize healthpack in gamemodel
       auto hp=world->getHealthPacks();
       gameModel->setHealthPacks(hp);



//initialize protagonist in gamemodel
            auto protagonist=world->getProtagonist();
            auto protagonist_model=make_shared<protagonistModel>();
            protagonist_model->setProtagonist(protagonist);
            auto protagonist_gamemodel = protagonist_model->getProtagonist();
            gameModel->setProtagonist(protagonist_model);



//initialize health and energy in both model and view
            gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getEnergy());
            ui->energy->setValue(gameModel->getProtagonist()->getProtagonist()->getEnergy());

            gameModel->getProtagonist()->getProtagonist()->setEnergy(world->getProtagonist()->getHealth());
            ui->health->setValue(gameModel->getProtagonist()->getProtagonist()->getHealth());

//tile
           /* for (auto &tile: gameModel->getTiles()){

                auto XPosTile=tile->getTile()->getXPos();
                auto YPosTile=tile->getTile()->getYPos();
                std::cout<<XPosTile<<","<<YPosTile<<std::endl;
            }*/

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
    QObject::connect(commandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
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


}



void MainWindow::updateEnergy(float value){
   // std::cout<<"energy"<<gameModel->getProtagonist()->getProtagonist()->getEnergy()<<std::endl;
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
    //scene = gameTextView->getScene();
   // scene->clear();
    scene->removeItem(textViewItem);
    textViewItem=scene->addText(buildview);
   // std::cout<<"jo"<<std::endl;
}



void MainWindow::on_comboBox_activated(int index)
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
}

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

