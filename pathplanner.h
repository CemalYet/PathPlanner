#ifndef PATHPLANNER_H
#define PATHPLANNER_H
#include "node.h"
#include "world.h"
#include <queue>
#include <vector>
#include <memory>
#include <algorithm>    // std::reverse

using namespace std;

class PathPlanner
{
public:
    PathPlanner(shared_ptr<World> &w,float slider);


    vector<pair<int,int>> solution(int goalX,int goalY);
    float findDistance(int x1,int y1,int x2,int y2) const;
    vector<pair<int,int>> fillPath(shared_ptr<Node> &node);
    void addTile(unique_ptr<Tile> tiles,vector<unique_ptr<Tile>> &data) ;
    void addAll(vector<unique_ptr<Tile>> &tiles,vector<unique_ptr<Tile>> &data);
    vector<unique_ptr<Tile> > getGameBoard() ;
    vector<pair<int,int>> solution1(int goalX,int goalY);

private:
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost > openList;
    vector<shared_ptr<Node>> closedList;
    vector<unique_ptr<Tile>> gameBoard;
    unique_ptr<Protagonist> protogonist;
    vector<unique_ptr<Enemy>> enemies;
    vector<unique_ptr<Tile>> healtPackets;


    priority_queue<pair<float,shared_ptr<Node>>,vector<pair<float,shared_ptr<Node>>>, std::greater<pair<float,shared_ptr<Node>>> > openQueue;
    unordered_map <unsigned int,pair<bool,float>> lookUp;
    int col;
    int row;
    float slider;





};

#endif // PATHPLANNER_H

