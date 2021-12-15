#include "textcommands.h"

TextCommands::TextCommands(std::shared_ptr<GameModel>gameMdl, std::shared_ptr<ViewText> textVw)
    :gameModel{gameMdl},textView{textVw}
{

}

void TextCommands::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


