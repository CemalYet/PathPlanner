#ifndef TEXTCOMMANDS_H
#define TEXTCOMMANDS_H
#include <string>
#include <list>
#include "gameModel.h"
#include "ViewText.h"


class TextCommands
{

private:

public:
    //TextCommands(std::shared_ptr<GameModel>gameMdl,std::shared_ptr<ViewText>textVw);
    TextCommands();
    virtual void execute(const std::string &command,std::list<std::string> commandExtras)=0;
};

#endif // TEXTCOMMANDS_H
