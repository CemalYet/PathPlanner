#include "nearestenemycommand.h"
#include "pathplanner.h"

NearestEnemyCommand::NearestEnemyCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{gameMdl,textVw}
{

}

void NearestEnemyCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{

    auto enemies=gameModel->getEnemyTileMap();
    float minDistance=std::numeric_limits<float>::infinity();
    float protagonistHealth=gameModel->getProtagonist()->getProtagonist()->getHealth();
    shared_ptr<Enemy>nearestEnemy;
    std::vector<pair<int,int>>pathToNearestEnemy;
    shared_ptr<PathPlanner>pathplanner=make_shared<PathPlanner>(gameModel,1);
    for(auto &e : enemies){

        int xpos=e.second->getXPos();
        int ypos=e.second->getYPos();
        if(!(e.second->getDefeated())){

            auto enemySolution=pathplanner->solution1(xpos,ypos);
            int nearestEnemyDistance=enemySolution.second.size();

            if(nearestEnemyDistance < minDistance){
                minDistance=nearestEnemyDistance;
                nearestEnemy=e.second;
                pathToNearestEnemy=enemySolution.second;

            }
        }
    }

//std::cout<<"path"<<pathToNearestEnemy.size()<<std::endl;
auto enemyXpos=nearestEnemy->getXPos();
auto enemyYPos=nearestEnemy->getYPos();
std::reverse(pathToNearestEnemy.begin(),pathToNearestEnemy.end());
float healthNeededToAttack=nearestEnemy->getValue();

if(protagonistHealth >=healthNeededToAttack){
        if(pathToNearestEnemy.size()!=0){
            for(auto &t:pathToNearestEnemy){

                auto valueOfTile=gameModel->getTileAtAPos(t.first,t.second)->getTile()->getValue();
                gameModel->clearProtagonistFromMap();//clear current protagonist from map
                auto protagonistXPosition=gameModel->getProtagonist()->getProtagonist()->getXPos();
                auto protagonistYPosition=gameModel->getProtagonist()->getProtagonist()->getYPos();
                textView->clearProtagonistTileView(protagonistXPosition,protagonistYPosition);//clear current position of protagonist from view as well

                gameModel->getProtagonist()->decreaseEnergy(valueOfTile);//reduce energy
                gameModel->getProtagonist()->getProtagonist()->setPos(t.first,t.second);//set protagonist new position
                gameModel->updateProtagonistPositionInMap();//update new position in map as well


                textView->updateProgonistTileView(t.first,t.second); //update protogonist position to the changed position

                auto updatedView=textView->buildPartialView(t.first,t.second);
                std::cout<<t.first<<","<<t.second<<std::endl;
                emit updateMainWindowView(updatedView);
                auto protogonistEnergy=gameModel->getProtagonist()->getProtagonist()->getEnergy();
                /*if(protogonistEnergy <=0){
                    QString message="Game over";
                    emit gameover(message);
                }*/
                delay();
                }


            std::cout<<enemyXpos<<","<<enemyYPos<<std::endl;
            auto tileWhereEnemyLocated=gameModel->getTileAtAPos(enemyXpos,enemyYPos)->getTile();
            auto enemyT=gameModel->getEnemyTileFromEnemyTileMap(enemyXpos,enemyYPos);
            enemyT->setDefeated(true);
            enemyT->setValue(std::numeric_limits<double>::infinity());//make enemy defeated
            tileWhereEnemyLocated->setValue(std::numeric_limits<double>::infinity());//make tile impassable
            textView->updateDeadEnemyView(enemyXpos,enemyYPos); //set tile as blocked in view                                                //make it as blocked in view
            gameModel->getProtagonist()->decreaseHealth(enemyT->getValue());
            gameModel->getProtagonist()->increaseEnergy();//max energy restored*/
         }
    }
    else {
        QString message="Game over";
        emit gameover(message);
    }
}
