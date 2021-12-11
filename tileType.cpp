#include "tileType.h"

std::string getStringForEnum(TileType enum_val)
{
    switch (enum_val)
        {
            case TileType::Protagonist: return "P";
            case TileType::PEnemy: return "Y";
            case TileType::Enemy: return "E";
            case TileType::XEnemy: return "X";
            case TileType::HealthPack: return "H";
            case TileType::Blocked : return "B";
            case TileType::NormalTile:
            default:return "0";
        }
}
