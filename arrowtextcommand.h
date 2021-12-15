#ifndef ARROWTEXTCOMMAND_H
#define ARROWTEXTCOMMAND_H

#include "textcommands.h"
#include "ViewText.h"


class ArrowTextCommand : public QObject,public TextCommands
{
Q_OBJECT
private:
    //std::shared_ptr<ViewText>textView;
    void checkIfNextTileType(const int &xpos,const int &ypos);

public:
    ArrowTextCommand(std::shared_ptr<GameModel> gameMdl,std::shared_ptr<ViewText>textVw);
    //ArrowTextCommand(std::unique_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw);
    void execute(const std::string &command, std::list<std::string> commandExtras)override;
signals:
    void gameover(const QString &message);

};

#endif // ARROWTEXTCOMMAND_H
