#include "arrowtextcommand.h"

ArrowTextCommand::ArrowTextCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{gameMdl,textVw}
{

}


void ArrowTextCommand::checkIfNextTileType(const int &xpos, const int &ypos)//different action based on tile type
{
    auto tileT=gameModel->getTileType(xpos,ypos);
    float tileValue=gameModel->getTileAtAPos(xpos,ypos)->getTile()->getValue();

    float healthOfProtagonist=gameModel->getProtagonist()->getProtagonist()->getHealth();
    float energyOfProtagonist=gameModel->getProtagonist()->getProtagonist()->getEnergy();

    if(tileT==TileType::Enemy) {
           auto enemyT=gameModel->getEnemyTileFromEnemyTileMap(xpos,ypos);
           if(healthOfProtagonist >= enemyT->getValue()){ //health greater than enemy value
               std::shared_ptr<Tile> tileWhereEnemyLocated=gameModel->getTileAtAPos(xpos,ypos)->getTile();
               enemyT->setDefeated(true);
               enemyT->setValue(std::numeric_limits<double>::infinity());//make enemy defeated
               tileWhereEnemyLocated->setValue(std::numeric_limits<double>::infinity());//make tile impassable
               textView->updateDeadEnemyView(xpos,ypos); //set tile as blocked in view                                                //make it as blocked in view
               gameModel->getProtagonist()->decreaseHealth(enemyT->getValue());
               gameModel->getProtagonist()->increaseEnergy();//max energy restored
          }
          else{

               QString message="Game Over";//game over
               emit gameover(message);
          }
     }
    else if (tileT==TileType::HealthPack){
           std::shared_ptr<HealthPackModel> healthtile=gameModel->getHealthPackFromHealthTileMap(xpos,ypos);
           gameModel->getProtagonist()->increaseHealth(healthtile->getHealthPack()->getValue());//increase health
           healthtile->setIsPacked(true);//update it's status as packed
           healthtile->getHealthPack()->setValue(0);                                     //update its healthvalue as 0
           textView->updateTakenHealthPackView(xpos,ypos);              //update view as health pack taken view                                                   //update view as healthPackTaken
         }
    else if (tileT==TileType::NormalTile){
            if(energyOfProtagonist >=tileValue){      // decrease energy part
                gameModel->getProtagonist()->decreaseEnergy(tileValue);//if enough energy
            }
            else{
                QString message="Game Over";    //game over
                emit gameover(message);
            }
         }

}


void ArrowTextCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{
    auto protagonistCurrentXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistCurrentYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    std::shared_ptr<TileModel> tileAtPos;

    if (command == "left" and protagonistCurrentXPos >0){
        tileAtPos=gameModel->getTileAtAPos(protagonistCurrentXPos-1,protagonistCurrentYPos);
    } else if(command == "right" and protagonistCurrentXPos < gameModel->getCols()-1){
        tileAtPos=gameModel->getTileAtAPos(protagonistCurrentXPos+1,protagonistCurrentYPos);
    } else if(command == "up" and protagonistCurrentYPos >0){
        tileAtPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos-1);
    } else if(command == "down" and protagonistCurrentYPos < (gameModel->getRows()-1)){
        tileAtPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos+1);
    }

    if(tileAtPos != nullptr && !(tileAtPos->isObstacle())){
        gameModel->clearProtagonistFromMap();
        textView->clearProtagonistTileView(protagonistCurrentXPos,protagonistCurrentYPos);
        if (command == "left" and protagonistCurrentXPos >0){
            gameModel->getProtagonist()->moveLeft();
        } else if(command == "right" and protagonistCurrentXPos < gameModel->getCols()-1){
            gameModel->getProtagonist()->moveRight();
        } else if(command == "up" and protagonistCurrentYPos >0){
            gameModel->getProtagonist()->moveUp();
        } else if(command == "down" and protagonistCurrentYPos < (gameModel->getRows()-1)){
            gameModel->getProtagonist()->moveDown();
        }

    checkIfNextTileType(tileAtPos->getTile()->getXPos(),tileAtPos->getTile()->getYPos());//checkTileType
    gameModel->updateProtagonistPositionInMap();

    auto protagonistNewXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistNewYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
    textView->updateProgonistTileView(protagonistNewXPos,protagonistNewYPos);

    }
}
