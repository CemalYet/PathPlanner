#include "pathplanner.h"

PathPlanner::PathPlanner(shared_ptr<World> &w,float slider):slider(slider)
{
    auto tiles = w->getTiles();
    addAll(tiles,gameBoard);
    auto healthPackets=w->getHealthPacks();
    addAll(healthPackets,this->healtPackets);

    //add enemy when you got models

    this->protogonist=w->getProtagonist();
    this->column=w->getCols();
    this->row=w->getRows();
}

void PathPlanner::addAll( vector<unique_ptr<Tile>> &tiles,vector<unique_ptr<Tile>> &data){
    for(unsigned int i=0;i<tiles.size();i++){
        addTile(move(tiles[i]),data);
    }

}

 vector<unique_ptr<Tile> > PathPlanner::getGameBoard()
{
    return move(gameBoard);
}

void PathPlanner::addTile(unique_ptr<Tile> tile,vector<unique_ptr<Tile>> &data) {
    data.push_back(move(tile));
}

vector<pair<int,int>> PathPlanner::solution(int goalX,int goalY){
    closedList.clear();
    int startX=protogonist->getXPos();
    int startY=protogonist->getYPos();

    vector<pair<int,int>> dummy;
    float heuristicCost=findDistance(goalX,goalY,startX,startY);
    auto rootNode = make_shared<Node>(startX,startY,heuristicCost,0,nullptr);
    this->openList.push(rootNode);
    while (!this->openList.empty()) {
        auto currentNode = openList.top();
        openList.pop();
        if(currentNode->getXPos()==goalX && currentNode->getYPos()==goalY){
            dummy=fillPath(currentNode);
            break;
        }
        //check succesor
        checkSuccessor(currentNode,goalX,goalY);
        this->closedList.push_back(currentNode);
    }
    return dummy;
}


float PathPlanner::findDistance(int x1,int y1,int x2,int y2) const{
    return slider*(float)(abs(x1-x2) + abs(y1-y2));
}

vector<pair<int,int>> PathPlanner::fillPath(shared_ptr<Node> &node){
    vector<pair<int,int>> dummy;
    auto tempNode=node;
    while (tempNode->getParent()) {
        dummy.push_back(make_pair(tempNode->getXPos(),tempNode->getYPos()));
        tempNode=tempNode->getParent();
    }
    reverse(dummy.begin(),dummy.end());
    return dummy;
}

void PathPlanner::checkSuccessor(shared_ptr<Node> currentNode,int goalX,int goalY){
    int x=currentNode->getXPos();
    int y=currentNode->getYPos();
    int posX []={x-1, x+1, x-1, x  , x+1, x-1, x  , x+1};
    int posY []={y  , y  , y-1, y-1, y-1, y+1, y+1, y+1};
    for(int i=0;i<8;i++){
        if(posX [i] >= 0 && posX [i] <column && posY [i] >= 0 && posY [i]<row){
           float value=gameBoard[column*posY[i]+posX[i]]->getValue();
            //move yaptigim iicin value null oluyor
            //float value=addTile(move(tiles[w->getCols()*posY[i]+posX[i]]));
            float givenCostOfSuccessor=currentNode->getGivenCost()+value;
            float heuristicOfSuccessor=findDistance(goalX,goalY,posX[i],posY[i]);
            if(value==std::numeric_limits<float>::infinity()){
                continue;
            }
            auto sucesssorNode = make_shared<Node>(posX[i],posY[i],heuristicOfSuccessor+givenCostOfSuccessor,givenCostOfSuccessor,currentNode);
            if(!isCreated(posX[i],posY[i],givenCostOfSuccessor)){
                continue;
            }
            this->openList.push(sucesssorNode);
        }

    }
}

bool PathPlanner::isCreated(int x,int y,float givenCost){
    for(unsigned int index=0;index<this->closedList.size();index++){
        if(this->closedList[index]->getXPos()==x && this->closedList[index]->getYPos()==y){
            if(this->closedList[index]->getGivenCost()>givenCost){
                this->closedList.erase (this->closedList.begin()+index);
                return true;
            }else{
                return  false;
            }
        }
    }
    return true;
}







