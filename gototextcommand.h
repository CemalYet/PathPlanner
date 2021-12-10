#ifndef GOTOTEXTCOMMAND_H
#define GOTOTEXTCOMMAND_H

#include "textcommands.h"
#include "pathplanner.h"

class GoToTextCommand : public QObject,public TextCommands
{
    Q_OBJECT
public:

    GoToTextCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw);
   // GoToTextCommand(std::unique_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw);
    void execute(const std::string &command,std::list<std::string> commandExtras)override;
private:
shared_ptr<PathPlanner>path;
};

#endif // GOTOTEXTCOMMAND_H
