#include "pathplanner.h"

PathPlanner::PathPlanner( float slider)
    :

      slider(slider)
{}

void PathPlanner::addAll( vector<unique_ptr<Tile>> &tiles){
    for(unsigned int i=0;i<tiles.size();i++){
        addTile(move(tiles[i]));
    }

}

 vector<unique_ptr<Tile> > PathPlanner::getGameBoard()
{
    return move(gameBoard);
}

void PathPlanner::addTile(unique_ptr<Tile> tile) {

    gameBoard.push_back(move(tile));
    //cout<<"ahdash "<<tile->getXPos()<<tile->getYPos()<<endl;
    //return tile->getValue();
}

vector<pair<int,int>> PathPlanner::solution(int x_,int y_,shared_ptr<World> &w){
    /*for(unsigned int i=0;w->getTiles().size();i++){
        auto tiles = w->getTiles();
        auto tile=move(tiles[i]);
        cout<<"cekf;akjdlajd"<<endl;
        cout<<tile->getValue()<<endl;
    }*/
    //cout<<x_<<y_<<endl;
    closedList.clear();
    int startX=w->getProtagonist()->getXPos();
    int startY=w->getProtagonist()->getYPos();
    auto tiles = w->getTiles();
    addAll(tiles);
    //cout<<"ganeasdasdads "<<gameBoard.size()<<endl;

    vector<pair<int,int>> dummy;
    float heuristicCost=findDistance(x_,y_,startX,startY);
    auto rootNode = make_shared<Node>(startX,startY,heuristicCost,0,nullptr);

    this->openList.push(rootNode);

    while (!this->openList.empty()) {
        //cout<<openList.size()<<endl;
        auto currentNode = openList.top();
        openList.pop();

        if(currentNode->getXPos()==x_ && currentNode->getYPos()==y_){
            dummy=fillPath(currentNode);
            break;
        }

        //check succesor
        int x=currentNode->getXPos();
        int y=currentNode->getYPos();
        int posX []={x-1, x  , x+1, x-1, x+1, x-1, x  , x+1};
        int posY []={y+1, y+1, y+1, y  , y  , y-1, y-1, y-1};

        for(int i=0;i<8;i++){
           // cout<<i<<"=="<<endl;
            if(posX [i] >= 0 && posX [i] < w->getCols() && posY [i] >= 0 && posY [i]<w->getRows()){
               float value=gameBoard[w->getCols()*posY[i]+posX[i]]->getValue();
                //cout<<"MY VALUE"<<value<<endl;
                //move yaptigim iicin value null oluyor
                //float value=addTile(move(tiles[w->getCols()*posY[i]+posX[i]]));

                //cout<<posX[i]<<" "<<posY[i]<<" ===> "<<gameBoard[w->getCols()*posY[i]+posX[i]]->getXPos()<<gameBoard[w->getCols()*posY[i]+posX[i]]->getYPos()<<endl;
                //cout<<posY[i]<<" "<<posX[i]<<" ===> "<<w->getCols()*posY[i]+posX[i]<<endl;
                float givenCostOfSuccessor=currentNode->getGivenCost()+value;
                //cout<<x<<y<<endl;

                //RAMOYA SOR X MI YOKSA X_ MI????????
                float heuristicOfSuccessor=findDistance(x_,y_,posX[i],posY[i]);
                cout<<"MY GivenCost() "<<currentNode->getGivenCost()<<endl;
                //cout<<"MY getFinalCost "<<currentNode->getFinalCost()<<endl;
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
        this->closedList.push_back(currentNode);

    }
    return dummy;
}


float PathPlanner::findDistance(int x1,int y1,int x2,int y2) const{
    return (float)(abs(x1-x2) + abs(y1-y2));
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

void PathPlanner::checkSuccessor(shared_ptr<Node> currentNode,int goalX,int goalY,shared_ptr<World>& w){

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






