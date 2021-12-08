#ifndef ARROWTEXTCOMMAND_H
#define ARROWTEXTCOMMAND_H

#include "textcommands.h"
#include "ViewText.h"

class ArrowTextCommand : public TextCommands
{
private:
    //std::shared_ptr<ViewText>textView;
public:
    ArrowTextCommand(std::shared_ptr<GameModel> gameMdl,std::shared_ptr<ViewText>textVw);
    //ArrowTextCommand(std::unique_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw);
    void execute(const std::string &command, std::list<std::string> commandExtras)override;
};

#endif // ARROWTEXTCOMMAND_H
