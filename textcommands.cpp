#include "textcommands.h"

TextCommands::TextCommands(std::shared_ptr<GameModel>gameMdl, std::shared_ptr<ViewText> textVw)
    :gameModel{gameMdl},textView{textVw}

{

}

/*TextCommands::TextCommands(std::unique_ptr<GameModel>gameMdl, std::shared_ptr<ViewText> textVw)
    :gameModel{std::move(gameMdl)},textView{textVw}

{

}*/


