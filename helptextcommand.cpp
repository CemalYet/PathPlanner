#include "helptextcommand.h"


HelpTextCommand::HelpTextCommand(std::shared_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw,QPlainTextEdit *text):
    TextCommands{gameMdl,textVw},helptext{text}
{

}
/*HelpTextCommand::HelpTextCommand(std::unique_ptr<GameModel> gameMdl, std::shared_ptr<ViewText> textVw,QPlainTextEdit *text):
    TextCommands{std::move(gameMdl),textVw},helptext{text}
{

}*/

void HelpTextCommand::execute(const std::string &command, std::list<std::string> commandExtras)
{
    std::string str = "right:move right\nleft:move left\nup:move up\ndown:move down\ngoto x y:move to (x,y)\nattack:attack nearest enemy\nhealth:take nearest health pack\nhelp:help" ;
    QString qstr = QString::fromStdString(str);
    helptext->appendPlainText(qstr);
}
