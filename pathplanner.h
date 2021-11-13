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
    PathPlanner(float slider);


    vector<pair<int,int>> solution(int x, int y,shared_ptr<World> &W);
    int findDistance(int x1,int x2,int y1,int y2) const;
    vector<pair<int,int>> fillPath(shared_ptr<Node> node);
    void checkSuccessor(shared_ptr<Node> currentNode,int goalX,int goalY, shared_ptr<World> &tiles);
    bool isCreated(int x,int y,float givenCost);
    void addTile(unique_ptr<Tile> &tiles);
    void addAll(const vector<unique_ptr<Tile>> &tiles);


    const shared_ptr<World> &getW() const;

private:
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost > openList;
    vector<shared_ptr<Node>> closedList;
    vector<shared_ptr<Tile>> gameBoard;
    unique_ptr<Protagonist> protogonist;
    vector<unique_ptr<Enemy>> enemies;
    vector<unique_ptr<Tile>> healtPackets;

    int column;
    int row;
    float slider;




};

#endif // PATHPLANNER_H
