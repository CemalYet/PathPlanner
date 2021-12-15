#ifndef NEARESTENEMYCOMMAND_H
#define NEARESTENEMYCOMMAND_H

#include "textcommands.h"

class NearestEnemyCommand : public QObject,public TextCommands
{
    Q_OBJECT
public:
    NearestEnemyCommand(std::shared_ptr<GameModel> gameMdl,std::shared_ptr<ViewText>textVw);
    void execute(const std::string &command,std::list<std::string> commandExtras)override;
signals:
   void updateMainWindowView(QString buildview);
   void gameover(const QString &message);
};

#endif // NEARESTENEMYCOMMAND_H
