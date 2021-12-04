#include "pathplanner.h"




PathPlanner::PathPlanner(shared_ptr<World> &w,float slider):slider(slider)
{
    auto tiles = w->getTiles();
    addAll(tiles,gameBoard);
//    auto healthPackets=w->getHealthPacks();
//    addAll(healthPackets,this->healtPackets);

    //add enemy when you got models

    this->protogonist=w->getProtagonist();
    this->col=w->getCols();
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
    if(tile->getValue() != std::numeric_limits<float>::infinity()){
        tile->setValue(abs(1-(tile->getValue())));
}
    data.push_back(move(tile));
}


float PathPlanner::findDistance(int x1,int y1,int x2,int y2) const{
    return slider*(float)(abs(x1-x2) + abs(y1-y2));
}

vector<pair<int,int>> PathPlanner::fillPath(shared_ptr<Node> &node){
    vector<pair<int,int>> dummy;
    auto tempNode=node;
    while (tempNode->getParent()) {
        cout<<tempNode->getFinalCost()<<" X : "<<tempNode->getXPos()<<" Y : "<<tempNode->getYPos()<< endl;
        dummy.push_back(make_pair(tempNode->getXPos(),tempNode->getYPos()));
        tempNode=tempNode->getParent();

    }
    //reverse(dummy.begin(),dummy.end());
    return dummy;
}





//int xPos, int yPos, float finalCost, float givenCost, const std::shared_ptr<Node> &parent, bool isClosed

vector<pair<int,int>> PathPlanner::solution1(int goalX,int goalY){

    int posX []={-1, 1, 0, 0, -1, -1,+1, +1};
    int posY []={ 0, 0,+1,-1, +1, -1,+1, -1};

    auto start = std::chrono::system_clock::now();


    int startX=0;
    int startY=45;

    vector<pair<int,int>> dummy;

    float heuristicCost=findDistance(goalX,goalY,startX,startY);

    auto rootNode = make_shared<Node>(startX,startY,heuristicCost,0.0,nullptr);

    openQueue.push(make_pair(rootNode->getFinalCost(),rootNode));
    lookUp[startY*col+startX]=make_pair(false,rootNode->getGivenCost());


    while (!this->openQueue.empty()) {

        auto currentNode=openQueue.top().second;
        openQueue.pop();
        lookUp[currentNode->getYPos()*col + currentNode->getXPos()]=make_pair(true,currentNode->getGivenCost());


        int x=currentNode->getXPos();
        int y=currentNode->getYPos();

        if(x==goalX && y==goalY) {
            dummy=fillPath(currentNode);
            break;
        }

        for( int i=0;i<8;i++) {
             int sucX=x+posX[i];
             int sucY=y+posY[i];

            if(sucX >= 0 && sucX <col && sucY >= 0 && sucY<row){

                float value=gameBoard[sucY*col+sucX]->getValue();

                if(value != std::numeric_limits<float>::infinity()){
                    auto lookUpIndex =lookUp[sucY*col+sucX];

                    if(lookUpIndex.first==true){
                        continue;
                    }


                    float givenCostOfSuccessor = currentNode->getGivenCost()+value;

                    if(lookUpIndex.first==false and givenCostOfSuccessor >= lookUpIndex.second
                            and lookUpIndex.second!=0.0){

                        continue;
                    }

                    float heuristicOfSuccessor=findDistance(goalX,goalY,sucX,sucY);

                    float finalCost=givenCostOfSuccessor+heuristicOfSuccessor;




                    if(lookUpIndex.first==false and lookUpIndex.second !=0.0){

                        lookUp[sucY*col+sucX].second=givenCostOfSuccessor;
                        auto updatedNode=make_shared<Node>(sucX,sucY,finalCost,givenCostOfSuccessor,currentNode);
                        openQueue.push(make_pair(finalCost,updatedNode));

                    }else{
                        auto successorNode = make_shared<Node>(sucX,sucY,finalCost,givenCostOfSuccessor,currentNode);
                        openQueue.push(make_pair(finalCost,successorNode));
                        lookUp[sucY*col+sucX]=make_pair(false,givenCostOfSuccessor);

                    }

                }

                }

            }


        }

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    return dummy;
}






