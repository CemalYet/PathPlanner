#ifndef TILETYPE_H
#define TILETYPE_H
#include <string>
enum class TileType {Protagonist,NormalTile,Enemy, PEnemy, XEnemy, HealthPack};
std::string getStringForEnum( TileType enum_val );
#endif // TILETYPE_H
