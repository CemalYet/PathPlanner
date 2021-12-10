#ifndef HELPTEXTCOMMAND_H
#define HELPTEXTCOMMAND_H
#include "textcommands.h"
#include <QPlainTextEdit>


class HelpTextCommand: public QObject,public TextCommands
{
Q_OBJECT
public:
    HelpTextCommand(std::shared_ptr<GameModel> gameMdl,std::shared_ptr<ViewText>textVw, QPlainTextEdit *text);
    //HelpTextCommand(std::unique_ptr<GameModel> gameMdl,std::shared_ptr<ViewText>textVw, QPlainTextEdit *text);
    void execute(const std::string &command, std::list<std::string> commandExtras)override;

private:
    QPlainTextEdit *helptext;
};



#endif // HELPTEXTCOMMAND_H
