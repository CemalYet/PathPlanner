#ifndef NEARESTHEALTHPACKCOMMAND_H
#define NEARESTHEALTHPACKCOMMAND_H

#include "textcommands.h"

class NearestHealthPackCommand : public QObject,public TextCommands
{
Q_OBJECT
public:    
    NearestHealthPackCommand(std::shared_ptr<GameModel> gameMdl,std::shared_ptr<ViewText>textVw);
    void execute(const std::string &command, std::list<std::string> commandExtras)override;
signals:
   void updateMainWindowView(QString buildview);
   void gameover(const QString &message);
};

#endif // NEARESTHEALTHPACKCOMMAND_H
