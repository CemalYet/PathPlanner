#include "nearesthealthpackcommand.h"
#include "pathplanner.h"

NearestHealthPackCommand::NearestHealthPackCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{gameMdl,textVw}
{

}
void NearestHealthPackCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{
    auto healthPacks=gameModel->getHealthPacks();
    float minHealthDistance=std::numeric_limits<float>::infinity();
    std::shared_ptr<HealthPackModel> nearestHealthPack;
    std::vector<pair<int,int>>pathToNearestHealthPack;

    //find nearest health pack
    for(auto &h : healthPacks){

        if(!(h->getIsPacked())){
            int healthpackXpos=h->getHealthPack()->getXPos();
            int healthpackYpos=h->getHealthPack()->getYPos();
            int healthpackValue=h->getHealthPack()->getValue();

            shared_ptr<PathPlanner>pathplanner=make_shared<PathPlanner>(gameModel,1);
            auto healthSolution=pathplanner->solution1(healthpackXpos,healthpackYpos);
            auto nearestHealthPackDistance=healthSolution.second.size();

            if( nearestHealthPackDistance !=0 && (nearestHealthPackDistance < minHealthDistance)){
                minHealthDistance=nearestHealthPackDistance;
                nearestHealthPack=h;
                pathToNearestHealthPack=healthSolution.second;
            }
        }
     }
    std::reverse(pathToNearestHealthPack.begin(),pathToNearestHealthPack.end());
    for(auto &path :pathToNearestHealthPack){

        auto valueOfTile=gameModel->getTileAtAPos(path.first,path.second)->getTile()->getValue();
       // gameModel->clearProtagonistFromMap();//clear current protagonist from map
       // auto protagonistXPosition=gameModel->getProtagonist()->getProtagonist()->getXPos();
      //  auto protagonistYPosition=gameModel->getProtagonist()->getProtagonist()->getYPos();
      //  textView->clearProtagonistTileView(protagonistXPosition,protagonistYPosition);//clear current position of protagonist from view as well

        gameModel->getProtagonist()->decreaseEnergy(valueOfTile);//reduce energy
        gameModel->getProtagonist()->getProtagonist()->setPos(path.first,path.second);//set protagonist new position
      //  gameModel->updateProtagonistPositionInMap();//update new position in map as well

       // textView->updateProgonistTileView(path.first,path.second); //update protogonist position to the changed position
        auto updatedView=textView->buildPartialView(path.first,path.second);

        //std::cout<<"path:"<<path.first<<","<<path.second<<std::endl;
        emit updateMainWindowView(updatedView);
       // auto protogonistEnergy=gameModel->getProtagonist()->getProtagonist()->getEnergy();
        /*if(protogonistEnergy <=0){
            QString message="Game over";
            emit gameover(message);
        }*/
        delay();
        }

    auto healthPackXpos=nearestHealthPack->getHealthPack()->getXPos();
    auto healthPackYpos=nearestHealthPack->getHealthPack()->getYPos();
    //std::cout<<healthPackXpos<<","<<healthPackYpos<<std::endl;
    auto tileWhereHealthLocated=gameModel->getTileAtAPos(healthPackXpos,healthPackYpos)->getTile();
    auto healthPackTile=gameModel->getHealthPackFromHealthTileMap(healthPackXpos,healthPackYpos);
    gameModel->getProtagonist()->increaseHealth(healthPackTile->getHealthPack()->getValue());
    nearestHealthPack->setIsPacked(true);
    healthPackTile->getHealthPack()->setValue(0);//update its healthvalue as 0
    textView->updateTakenHealthPackView(healthPackXpos,healthPackYpos);//update view as health pack taken view

    }

