#include "pathplanner.h"

PathPlanner::PathPlanner( float slider)
    :

    slider(slider)
{}

void PathPlanner::addAll(const vector<unique_ptr<Tile>> &tiles){
    for(unsigned int i=0;i<tiles.size();i++){
        addTile(std::move(tiles[i]));
    }

}
void PathPlanner::addTile(unique_ptr<Tile> &tile){

        this->gameBoard.push_back(std::move(tile));


}

vector<pair<int,int>> PathPlanner::solution(int x,int y,shared_ptr<World> &w){
       closedList.clear();
       int startX=w->getProtagonist()->getXPos();
       int startY=w->getProtagonist()->getYPos();

       vector<pair<int,int>> dummy;
       float finalCost=findDistance(startX,startY,x,y);
       auto rootNode = make_shared<Node>(startX,startY,finalCost,0,nullptr);

       this->openList.push(rootNode);

       while (!this->openList.empty()) {
           cout<<openList.size()<<endl;
           auto currentNode = openList.top();
           openList.pop();

           if(currentNode->getXPos()==x && currentNode->getYPos()==y){

               dummy=fillPath(currentNode);
                break;
            }

           //check succesor
           int x=currentNode->getXPos();
           int y=currentNode->getYPos();
           int posX []={x-1,x,x+1,x-1,x+1,x-1,x,x+1};
           int posY [] ={y+1,y+1,y+1,y,y,y-1,y-1,y-1};

           for(int i=0;i<8;i++){
               cout<<"x="<<posX[i]<<" y="<<posY[i]<<endl;
               if(posX [i] >= 0 && posX [i]<w->getCols() && posY [i] >= 0 && posY [i]<w->getRows()){
                   shared_ptr<Tile> t=move(move(w->getTiles()[0]));
                  // shared_ptr<std::string> shared = std::make_unique<std::string>("test");
                   float val=t->getValue();
                   cout<<"closed size"<<closedList.size()<<endl;
                   int givenCostOfSuccessor=currentNode->getGivenCost()+val;
                   int heuristicOfSuccessor=findDistance(x,y,posX[i],posY[i]);
                   if(val==std::numeric_limits<float>::infinity()){
                       cout<<"hebele"<<endl;
                       continue;
                   }
                   if(!isCreated(posX[i],posY[i],givenCostOfSuccessor)){
                        cout<<"hubele"<<endl;
                       continue;
                   }
                      cout<<"ekeledimm"<<endl;
                     auto sucesssorNode = make_shared<Node>(posX[i],posY[i],heuristicOfSuccessor+givenCostOfSuccessor,givenCostOfSuccessor,currentNode);
                     this->openList.push(sucesssorNode);
               }

           }





           this->closedList.push_back(currentNode);

       }
       return dummy;


}

int PathPlanner::findDistance(int x1,int y1,int x2,int y2) const{
    return abs(x2-x1) + abs(y2-y1);
}

vector<pair<int,int>> PathPlanner::fillPath(shared_ptr<Node> node){
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






