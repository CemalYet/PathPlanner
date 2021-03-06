
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
    PathPlanner() {}
    PathPlanner(shared_ptr<GameModel> &w,float slider); //changed to shared pointer
    float findDistance(int x1,int y1,int x2,int y2) ;
    vector<pair<int,int>> fillPath(shared_ptr<Node> &node);

    pair<float,vector<pair<int,int>>> solution1(int goalX,int goalY);
    pair<bool,vector<vector<pair<int,int>>>> autoPlay();
    pair<bool,shared_ptr<Enemy>>findNearestEnemy(shared_ptr<Enemy> &nearestEnemy,pair<float,vector<pair<int,int>>> &path);
    shared_ptr<HealthPackModel> findNearestHealthPack(shared_ptr<HealthPackModel> &nearestHealthPack,pair<float,
                                                                    vector<pair<int,int>>> &path,const float &enemyPower,const float &pHealth);
    void setSlider(const float &newSlider);
    float getSlider() const;

    pair<bool, vector<pair<int, int>>> findNearestEnemyPath();
    pair<bool, vector<pair<int, int>>> findNearestHealthPack();

    void setGameBoard(const vector<shared_ptr<TileModel> > &newGameBoard);
    void setProtogonist(const shared_ptr<protagonistModel> &newProtogonist);
    void setEnemies(const std::map<std::string, std::shared_ptr<Enemy> > &newEnemies);
    void setHealtPackets(const vector<shared_ptr<HealthPackModel> > &newHealtPackets);
    void setCol(int newCol);
    void setRow(int newRow);

    const vector<shared_ptr<TileModel> > &getGameBoard() const;

    const std::map<std::string, std::shared_ptr<Enemy> > &getEnemies() const;

private:
    vector<shared_ptr<TileModel>> gameBoard;
    shared_ptr<protagonistModel> protogonist;
    std::map<std::string,std::shared_ptr<Enemy>> enemies;
    vector<shared_ptr<HealthPackModel>> healtPackets;
     //enemyTileMap;

    priority_queue<pair<float,shared_ptr<Node>>,vector<pair<float,shared_ptr<Node>>>, std::greater<pair<float,shared_ptr<Node>>> > openQueue;
    int col;
    int row;
    float slider;
    float stepCost{0.001};
};

#endif // PATHPLANNER_H
