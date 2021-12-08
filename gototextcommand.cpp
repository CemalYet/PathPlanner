#include "gototextcommand.h"


GoToTextCommand::GoToTextCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{gameMdl,textVw}
{

}

/*GoToTextCommand::GoToTextCommand(std::unique_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw)
    :TextCommands{std::move(gameMdl),textVw}
{

}*/

void GoToTextCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{

    auto protagonistCurrentXPos=gameModel->getProtagonist()->getProtagonist()->getXPos();
    auto protagonistCurrentYPos=gameModel->getProtagonist()->getProtagonist()->getYPos();

    auto protagonistTargetXpos=std::stoi(commandExtras.front());//string to int
    auto protagonistTargetYpos=std::stoi(commandExtras.back());


    path=make_shared<PathPlanner>(gameModel,1);
    auto tilesToHighlight=path->solution1(protagonistTargetXpos,protagonistTargetYpos);

    std::cout<<"number tiles to highlight"<<tilesToHighlight.size()<<std::endl;
    for(auto &highlightTiles:tilesToHighlight){
          cout<<'['<<highlightTiles.first<<','<<highlightTiles.second<<']'<<endl;
        }


}
