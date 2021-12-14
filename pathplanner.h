#ifndef PATHPLANNER_H
#define PATHPLANNER_H
#include "node.h"
#include "world.h"
#include <queue>
#include <vector>
#include <memory>
#include <algorithm>
#include "gameModel.h"


using namespace std;

class PathPlanner
{
public:
    PathPlanner(shared_ptr<GameModel> &w,float slider); //changed to shared pointer
    float findDistance(int x1,int y1,int x2,int y2) ;
    vector<pair<int,int>> fillPath(shared_ptr<Node> &node);
    vector<unique_ptr<Tile> > getGameBoard() ;
    pair<float,vector<pair<int,int>>> solution1(int goalX,int goalY);
    pair<bool,vector<vector<pair<int,int>>>> autoPlay();


private:
    vector<shared_ptr<TileModel>> gameBoard;
    shared_ptr<protagonistModel> protogonist;
    std::map<std::string,std::shared_ptr<Enemy>> enemies;
    vector<shared_ptr<HealthPackModel>> healtPackets;
     //enemyTileMap;

    priority_queue<pair<float,shared_ptr<Node>>,vector<pair<float,shared_ptr<Node>>>, std::greater<pair<float,shared_ptr<Node>>> > openQueue;
    //unordered_map <unsigned int,pair<bool,float>> lookUp;
    //pair<bool, float> lookUp[2380][2400];
    int col;
    int row;
    float slider;
    float stepCost{0.001};





};

#endif // PATHPLANNER_H
