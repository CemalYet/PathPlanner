#include "pathplanner.h"




PathPlanner::PathPlanner(unique_ptr<GameModel> &w,float slider):slider(slider)
{
    gameBoard = w->getTiles();
    protogonist = w->getProtagonist();
    col=w->getCols();
    row=w->getRows();
    healtPackets=w->getHealthPacks();
    enemies=w->getEnemyTileMap();
}




float PathPlanner::findDistance(int x1,int y1,int x2,int y2) {
    //return slider*(float)(abs(x1-x2)+abs(y1-y2));
    //return slider*sqrt(pow(x2 - x1, 2) +
    //pow(y2 - y1, 2));
    float dx = abs(x1-x2);
    float dy = abs(y1-y2);
    return slider * ((dx + dy) + (1.414 - 2) * min(dx, dy));
}

//solution path
vector<pair<int,int>> PathPlanner::fillPath(shared_ptr<Node> &node){
    vector<pair<int,int>> dummy;
    auto tempNode=node;
    while (tempNode->getParent()) {
        dummy.push_back(make_pair(tempNode->getXPos(),tempNode->getYPos()));
        tempNode=tempNode->getParent();

    }
    return dummy;
}

//returns as a first total cost of path and as a second solution path vector
pair<float,vector<pair<int,int>>> PathPlanner::solution1(int goalX,int goalY){
    //initialize lookUp vector
    vector<pair<bool,float>> d (col,make_pair(false,0.0));
    vector<vector<pair<bool,float>>> lookUp(row,d);

    //set 8 tiles A* needs to check
    int posX []={-1,  1, -1, 0,  1, -1, 0, 1};
    int posY []={ 0 , 0 ,-1,-1, -1,  1, 1, 1};

    //auto start = std::chrono::system_clock::now();

    //Get protagonist position
    int startX=protogonist->getProtagonist()->getXPos();
    int startY=protogonist->getProtagonist()->getYPos();

    //initialize solution vector
    vector<pair<int,int>> dummy;

    float totalGivenCost;
    float heuristicCost=findDistance(goalX,goalY,startX,startY);

    auto rootNode = make_shared<Node>(startX,startY,0,nullptr);
    openQueue.emplace(make_pair(heuristicCost,rootNode));
    lookUp[startY][startX]=make_pair(false,0);
    //lookUp[startY*col+startX]=make_pair(false,0);


    while (!openQueue.empty()) {
        auto currentNode=openQueue.top().second;
        openQueue.pop();
        int x=currentNode->getXPos();
        int y=currentNode->getYPos();
        lookUp[y][x].first=true;
        float currentNodeGivenCost = currentNode->getGivenCost();
        //lookUp[y*col+x]=make_pair(true,currentNode->getGivenCost());
        //lookUp[y*col+x].first=true;


        if(x==goalX && y==goalY) {
            dummy=fillPath(currentNode);
            totalGivenCost=currentNodeGivenCost;
            break;
        }

        for( int i=0;i<8;i++) {
            int sucX=x+posX[i];
            int sucY=y+posY[i];

            if(sucX >= 0 && sucX <col && sucY >= 0 && sucY < row){

                float value=gameBoard[col*sucY+sucX]->getTile()->getValue();
                //auto lookUpIndex =lookUp[col*sucY+sucX];
                auto lookUpIndex =lookUp[sucY][sucX];

                if(value != std::numeric_limits<float>::infinity() and !(lookUpIndex.first==true)){

                    float givenCostOfSuccessor=currentNodeGivenCost+value+0.001;


                    if(!(lookUpIndex.first==false and lookUpIndex.second !=0.0) or (lookUpIndex.first==false and givenCostOfSuccessor <
                                                                                    lookUpIndex.second and lookUpIndex.second!=0.0)){
                        float heuristicOfSuccessor=findDistance(goalX,goalY,sucX,sucY);
                        float finalCost=givenCostOfSuccessor+heuristicOfSuccessor;

                        auto successorNode = make_shared<Node>(sucX,sucY,givenCostOfSuccessor,currentNode);
                        openQueue.emplace(make_pair(finalCost,successorNode));
                        lookUp[sucY][sucX].second=givenCostOfSuccessor;
                        //lookUp[col*sucY+sucX].second=givenCostOfSuccessor;
                        lookUp[sucY][sucX].first=false;
                        //lookUp[col*sucY+sucX].first=false;


                    }


                }

            }

        }

    }

   // auto end = std::chrono::system_clock::now();

    //std::chrono::duration<double> elapsed_seconds = end-start;
    //cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    return make_pair(totalGivenCost,dummy);
}

//returns win or game-over as well as path that protagonist followed
pair<bool,vector<vector<pair<int,int>>>> PathPlanner::autoPlay()
{
    vector<vector<pair<int,int>>> simulatorPath;
    unsigned int counter=0;
    bool iskilled=true;
    shared_ptr<Enemy> nearestEnemy;
    while(counter < enemies.size()){
        int pH=protogonist->getProtagonist()->getHealth();
        int pE=protogonist->getProtagonist()->getEnergy();
        float minDistance=std::numeric_limits<float>::infinity();
        pair<float,vector<pair<int,int>>> path;

        //if protogonist killed the enemy
        if (iskilled)
        {
            //finds nearest enemy
            for(auto &e : enemies){
                int eX=e.second->getXPos();
                int eY=e.second->getYPos();

                if(!(e.second->getDefeated())){
                    auto enemySolution=solution1(eX,eY);
                    int nearestEnemyDistance=enemySolution.second.size();

                    if(nearestEnemyDistance < minDistance){
                        minDistance=nearestEnemyDistance;
                        nearestEnemy=e.second;
                        path=enemySolution;
                        iskilled=false;

                    }
                }

            }
        }
        //go to the prev enemy
        else {
             auto e=nearestEnemy;
             path=solution1(e->getXPos(),e->getYPos());
        }

        if(nearestEnemy==nullptr){
            return make_pair(false,simulatorPath);
        }
        float enemyValue=nearestEnemy->getValue();
        //if protagonist health and energy greater than enemy value and total path energy
        //do the following
        if(pH > enemyValue and pE > path.first){
            protogonist->decreaseEnergy(path.first);
            protogonist->decreaseHealth(enemyValue);
            protogonist->goTo(nearestEnemy->getXPos(),nearestEnemy->getYPos());
            protogonist->increaseEnergy();
            nearestEnemy->setDefeated(1);
            gameBoard[col*nearestEnemy->getYPos()+nearestEnemy->getXPos()]->setInfinity();
            simulatorPath.push_back(path.second);
            counter++;
            iskilled=true;
            //add to solution path

        //protagonist health not enough go to nearest appropriate health pack
        }else if( pH <= enemyValue and pE > path.first){
            float minHealthDistance=std::numeric_limits<float>::infinity();
            shared_ptr<HealthPackModel> nearestHealthPack;

            //find nearest health pack
            for(auto &h : healtPackets){

                int hX=h->getHealthPack()->getXPos();
                int hY=h->getHealthPack()->getYPos();
                int hV=h->getHealthPack()->getValue();

                auto healthSolution=solution1(hX,hY);
                auto nearestHealthPackDistance=healthSolution.second.size();

                if(nearestHealthPackDistance < minHealthDistance and pH + hV > enemyValue){
                    minHealthDistance=nearestHealthPackDistance;
                    nearestHealthPack=h;
                    path=healthSolution;

                }

            }
            //if health pack value enough do following
            if(path.second.size()>0 and pE > path.first and !(nearestHealthPack->getIsPacked())){
                protogonist->increaseHealth(nearestHealthPack->getHealthPack()->getValue());
                protogonist->goTo(nearestHealthPack->getHealthPack()->getXPos(),nearestHealthPack->getHealthPack()->getYPos());
                nearestHealthPack->setIsPacked(true);
                simulatorPath.push_back(path.second);

            }else{
                return  make_pair(false,simulatorPath);
            }

        }else{
            return make_pair(false,simulatorPath);
        }

    }

   return make_pair(true,simulatorPath);
}

