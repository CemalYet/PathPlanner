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
            case TileType::TakenHealthpack: return "T";
            case TileType::NormalTile:
            default:return "0";
        }
}


static bool isEnemy(TileType type)
{
   return (type== TileType::PEnemy) || (type== TileType::Enemy) ||(type== TileType::XEnemy);
}
