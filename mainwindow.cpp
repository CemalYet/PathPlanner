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
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto world = make_shared<World>();
    world->createWorld(":/images/worldmap.jpg",10,5);
    gameModel = std::make_shared<GameModel>();


   // auto pathPlanner=make_shared<PathPlanner>(world,0.2);
    //vector<pair<int,int>> dummy=pathPlanner->solution1(4,4);
    //auto tiles=pathPlanner->getGameBoard();


    //cout<<"PATH === "<<dummy.size()<<endl;

   /* for (auto &d :dummy ) {
        for(int i=0;i<world->getCols();i++){
                cout<<"|";
                for(int y=0;y<world->getRows();y++){
                    if(i==d.second && y==d.first){
                        cout<<"p"<<" |";
                    } else{
                         cout<< tiles[i*world->getCols()+y]->getValue()<<" |";
                    }
                }
                cout<<endl;
            }

        cout<<d.first<<d.second<<endl;
    }*/



            auto world_tiles=world->getTiles();
            gameModel->setTiles(world_tiles);//comment
          /* auto gamemodel_tiles=gameModel->getTiles();
            int xpos;
            int ypos;
            int index;
            cout<<"Tiles at location"<<endl;
            for(auto &e:gamemodel_tiles){
                xpos=e->getTile()->getXPos();
                ypos=e->getTile()->getYPos();
               // cout<<'['<<xpos<<','<< ypos<<"]"<<endl;
                cout<<'['<<xpos<<','<< ypos<<"] "<<e->getTile()->getValue()<<endl;

           }//comment*/

            auto row=world->getRows();
            auto col=world->getCols();


            gameModel->setRows(row);
            gameModel->setCols(col);




       auto enemy=world->getEnemies();
        gameModel->setEnemies(enemy);//comment
        /*auto enemies_gamemodel=gameModel->getEnemies();
        std::cout<<"enemies at location"<<std::endl;
        for(auto &e:enemies_gamemodel){
              cout<<'['<<e->getEnemy()->getXPos()<<','<<e->getEnemy()->getYPos()<<']'<<endl;
              std::vector<std::shared_ptr<Tile>> healthPacks;
            }//comment*/


        auto penemies_gamemodel=gameModel->getPEnemies();
        /*std::cout<<"Penemies at location"<<std::endl;
        for(auto &e:penemies_gamemodel){
              cout<<'['<<e->getPEnemy()->getXPos()<<','<<e->getPEnemy()->getYPos()<<']'<<endl;
            }*/

       auto hp=world->getHealthPacks();
       gameModel->setHealthPacks(hp);





        //Test Xenemies and set their positions

           /* std::cout<<"Xenemies at"<<endl;
            int xPos=0; int yPos=0;
            XenemyModel setXenemies;
            auto actual_xenemies= gameModel->getPEnemies();

            for(auto &x_enemy:actual_xenemies){
                cout<<'['<<(x_enemy->getPEnemy()->getXPos())/2 <<','<<x_enemy->getPEnemy()->getYPos() + rand() % 2+1<<']'<<endl;
                xPos = x_enemy->getPEnemy()->getXPos() + rand();
                if(xPos > 30){
                    xPos = xPos - rand() % 25 + 1;
                }
                yPos = x_enemy->getPEnemy()->getYPos() + rand();
                if (yPos > 30){
                    yPos = yPos - rand() % 25 + 1;
                }
                setXenemies.setXEnemy(xPos, yPos);
                }*/



            auto protagonist=world->getProtagonist();
            auto protagonist_model=make_shared<protagonistModel>();
            protagonist_model->setProtagonist(protagonist);
            auto protagonist_gamemodel = protagonist_model->getProtagonist();
            gameModel->setProtagonist(protagonist_model);
            /*auto actual_protagonist=gameModel->getProtagonist();

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
                cout<<'['<<h->getHealthPack()->getXPos()<<','<<h->getHealthPack()->getYPos()<<']'<<endl;
            }*/



/*auto tile=gameModel->getTileAtAPos(4,1);
std::cout<<tile->getXPos() <<","<<tile->getYPos();*/
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
    //std::cout<<"row"<<gameModel->getRows()<<std::endl;
    gameTextView =std::make_shared<ViewText>(gameModel->getRows(),gameModel->getCols());
    scene = gameTextView->getScene();
   // scene->setSceneRect(0,0,100,100);//added
    scene->setSceneRect(0,0,1920,1080);
    ui->graphicsView->setScene(scene);


    for (auto &tile: gameModel->getTiles()){

        auto XPosTile=tile->getTile()->getXPos();
        auto YPosTile=tile->getTile()->getYPos();
        auto valueTile=tile->getTile()->getValue();
        auto tileType=gameModel->getTileType(XPosTile,YPosTile);
        gameTextView->setTextTileView(XPosTile,YPosTile,valueTile,tileType);
    }

    //textViewItem=scene->addText(gameTextView->buildView());
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
       //std::cout<<"joined string"<<std::stoi(joinedString.back())+1<<std::endl;

     }
}

void MainWindow::createTextCommandToClassMap()
{
    //std::shared_ptr<GameModel> gm=std::move(gameModel);
    //auto commandObject =  std::make_shared<ArrowTextCommand>(gm,gameTextView);
    auto commandObject =  std::make_shared<ArrowTextCommand>(gameModel,gameTextView);
    textCommandToClassMap["right"]=commandObject;
    textCommandToClassMap["left"]=commandObject;
    textCommandToClassMap["up"]=commandObject;
    textCommandToClassMap["down"]=commandObject;
    textCommandToClassMap["goto"]=std::make_shared<GoToTextCommand>(gameModel,gameTextView);
    textCommandToClassMap["help"]=std::make_shared<HelpTextCommand>(gameModel,gameTextView,ui->helpResponse);
    QObject::connect(commandObject.get(),SIGNAL(gameover(const QString)),this,SLOT(gameOverSlot(const QString)));
}


void MainWindow::on_executeButton_clicked()
{
    ui->helpResponse->clear();
    QString inputCommand=ui->userInput->toPlainText();
    processTextCommand(inputCommand.toLower());
    scene->removeItem(textViewItem);
    //textViewItem=scene->addText(gameTextView->buildView());
    auto protagonistXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();

    textViewItem=scene->addText(gameTextView->buildPartialView(protagonistXPos,protagonistYPos));
    updateEnergy(gameModel->getProtagonist()->getProtagonist()->getEnergy());
    updateHealth(gameModel->getProtagonist()->getProtagonist()->getHealth());


}



void MainWindow::updateEnergy(float value){
    std::cout<<"energy"<<gameModel->getProtagonist()->getProtagonist()->getEnergy()<<std::endl;
    ui->energy->setValue(value);

}

void MainWindow::updateHealth(float value)
{
     std::cout<<"health"<<gameModel->getProtagonist()->getProtagonist()->getHealth()<<std::endl;
     ui->health->setValue(value);
}

void MainWindow::gameOverSlot(const QString &message)
{
    ui->textBrowser->setStyleSheet("background-color: red;");
    ui->textBrowser->setText(message);
}







