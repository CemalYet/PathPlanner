#include "gototextcommand.h"
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>


GoToTextCommand::GoToTextCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{gameMdl,textVw}
{

}



void GoToTextCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{


    if(commandExtras.size() >2){
        std::cout<<commandExtras.size()<<" invalid"<<std::endl;
    }
    else{
        auto protagonistTargetXpos=std::stoi(commandExtras.front());//string to int
        auto protagonistTargetYpos=std::stoi(commandExtras.back());

        shared_ptr<PathPlanner>pathplanner=make_shared<PathPlanner>(gameModel,1);
        vector<pair<int,int>> tilesInThePath=pathplanner->solution1(protagonistTargetXpos,protagonistTargetYpos).second;
        std::reverse(tilesInThePath.begin(),tilesInThePath.end());

        for(auto &t:tilesInThePath){
            auto tileT=gameModel->getTileType(t.first,t.second);
            auto getTile=gameModel->getTileAtAPos(t.first,t.second)->getTile();
            auto valueOfTile=getTile->getValue();
            auto getProtagonist=gameModel->getProtagonist()->getProtagonist();

           /* if(tileT == TileType::Enemy){
                auto enemyT=gameModel->getEnemyTileFromEnemyTileMap(t.first,t.second);

                if(getProtagonist->getEnergy() >= enemyT->getValue()){//if protagonist have enough enrgy to attack enemy

                   // gameModel->clearProtagonistFromMap();//clear current protagonist from map
                   // textView->clearProtagonistTileView(protagonistCurrentXPos,protagonistCurrentYPos);//clear current position of protagonist from view as well

                    //gameModel->getProtagonist()->decreaseEnergy(valueOfTile);//reduce energy
                    gameModel->getProtagonist()->decreaseHealth(enemyT->getValue());//decrease health with enemy value
                    gameModel->getProtagonist()->increaseEnergy();//restore energy to max when defeated
                  //  getProtagonist->setPos(t.first,t.second);//set protagonist new position
                  //  gameModel->updateProtagonistPositionInMap();//update new position in map as well


                    enemyT->setDefeated(true);
                    enemyT->setValue(std::numeric_limits<double>::infinity());//make enemy defeated
                    getTile->setValue(std::numeric_limits<double>::infinity());//make tile impassable
                    textView->updateDeadEnemyView(t.first,t.second); //set tile as blocked in view

                   // auto protagonistNewXPos=getProtagonist->getXPos();
                  //  auto protagonistNewYPos=getProtagonist->getYPos();
                  //  std::cout<<protagonistNewXPos<<","<<protagonistNewYPos<<std::endl;
                   // textView->updateProgonistTileView(protagonistNewXPos,protagonistNewYPos); //update protogonist position to the changed position

                }
                else{
                    std::cout<<"enemy ahead and not enough energy to attack enemy"<<std::endl;
                    break;
                }
            }*/

            //if(tileT==TileType::NormalTile){

                //std::cout<<"path"<<t.first<<t.second<<std::endl;
                gameModel->clearProtagonistFromMap();//clear current protagonist from map
                textView->clearProtagonistTileView(getProtagonist->getXPos(),getProtagonist->getYPos());//clear current position of protagonist from view as well

                gameModel->getProtagonist()->decreaseEnergy(valueOfTile);//reduce energy
                gameModel->getProtagonist()->getProtagonist()->setPos(t.first,t.second);//set protagonist new position
                gameModel->updateProtagonistPositionInMap();//update new position in map as well
                qDebug() << "goto text protagonist X_pos is" << gameModel->getProtagonist()->getProtagonist()->getXPos();
                qDebug() << "goto text protagonist Y_pos is" << gameModel->getProtagonist()->getProtagonist()->getYPos();


                textView->updateProgonistTileView(t.first,t.second); //update protogonist position to the changed position

                auto updatedView=textView->buildPartialView(t.first,t.second);
                emit updateMainWindowView(updatedView);
                if(getProtagonist->getEnergy() <=0){
                    QString message="Game over";
                    emit gameover(message);
                }
                delay();

            //}
              if(tileT == TileType::HealthPack){
               auto healthtile=gameModel->getHealthPackFromHealthTileMap(t.first,t.second)->getHealthPack();
               gameModel->getProtagonist()->increaseHealth(healthtile->getValue());//increase energy                                                                        //update it's status as packed
               healthtile->setValue(0);                                     //update its healthvalue as 0
               textView->updateTakenHealthPackView(t.first,t.second);              //update view as health pack taken view
           }
        }

    std::cout<<"Size of the path"<<tilesInThePath.size()<<std::endl;
    }
}


