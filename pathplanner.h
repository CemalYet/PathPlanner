#ifndef PATHPLANNER_H
#define PATHPLANNER_H
#include "node.h"
#include "world.h"
#include <queue>
#include <vector>
#include <memory>
using namespace std;

class PathPlanner
{
public:
    PathPlanner();

private:
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, OrderByFinalCost > openList;
    vector<shared_ptr<Node>> closedList;



};

#endif // PATHPLANNER_H
