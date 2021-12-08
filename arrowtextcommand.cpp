#include "arrowtextcommand.h"

ArrowTextCommand::ArrowTextCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{gameMdl,textVw}
{

}
/*ArrowTextCommand::ArrowTextCommand(std::unique_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{std::move(gameMdl),textVw}
{

}*/

void ArrowTextCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{
    auto protagonistCurrentXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistCurrentYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();

    if (command == "left" and protagonistCurrentXPos >0){
         auto tileAtLeftPos=gameModel->getTileAtAPos(protagonistCurrentXPos-1,protagonistCurrentYPos);
         if(!(tileAtLeftPos->isObstacle())){
               gameModel->clearProtagonistFromMap();
               textView->clearProtagonistTileView(protagonistCurrentXPos,protagonistCurrentYPos);
               gameModel->getProtagonist()->moveLeft();
               gameModel->updateProtagonistPositionInMap();
               auto protagonistNewXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
               auto protagonistNewYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
               textView->updateProgonistTileView(protagonistNewXPos,protagonistNewYPos);
         }
     }
    else if(command == "right" and protagonistCurrentXPos < gameModel->getCols()-1){
         auto tileAtRightPos=gameModel->getTileAtAPos(protagonistCurrentXPos+1,protagonistCurrentYPos);
         if(!(tileAtRightPos->isObstacle())){
             gameModel->clearProtagonistFromMap();
             textView->clearProtagonistTileView(protagonistCurrentXPos,protagonistCurrentYPos);

             gameModel->getProtagonist()->moveRight();
             gameModel->updateProtagonistPositionInMap();

             auto protagonistNewXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
             auto protagonistNewYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
             textView->updateProgonistTileView(protagonistNewXPos,protagonistNewYPos);
         }
      }


     else if(command == "up" and protagonistCurrentYPos >0){
        auto tileAtRightPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos-1);
        if(!(tileAtRightPos->isObstacle())){
            gameModel->clearProtagonistFromMap();
            textView->clearProtagonistTileView(protagonistCurrentXPos,protagonistCurrentYPos);

            gameModel->getProtagonist()->moveUp();
            gameModel->updateProtagonistPositionInMap();

            auto protagonistNewXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
            auto protagonistNewYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
            textView->updateProgonistTileView(protagonistNewXPos,protagonistNewYPos);
        }

        }


    else if(command == "down" and protagonistCurrentYPos < (gameModel->getRows()-1)){
        auto tileAtRightPos=gameModel->getTileAtAPos(protagonistCurrentXPos,protagonistCurrentYPos+1);
        if(!(tileAtRightPos->isObstacle())){
            gameModel->clearProtagonistFromMap();
            textView->clearProtagonistTileView(protagonistCurrentXPos,protagonistCurrentYPos);

            gameModel->getProtagonist()->moveDown();
            gameModel->updateProtagonistPositionInMap();

            auto protagonistNewXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
            auto protagonistNewYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();
            textView->updateProgonistTileView(protagonistNewXPos,protagonistNewYPos);
        }


        }
}
