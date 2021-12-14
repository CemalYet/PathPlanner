#ifndef TILETYPE_H
#define TILETYPE_H
#include <string>
enum class TileType {Protagonist,NormalTile,Enemy, PEnemy, XEnemy, HealthPack, Blocked,TakenHealthpack};
std::string getStringForEnum( TileType enum_val );
static bool isEnemy(TileType type);
#endif // TILETYPE_H
