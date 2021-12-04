#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <memory>


class Node
{
public:
    Node(int xPos, int yPos, float finalCost, float givenCost, const std::shared_ptr<Node> &parent);

    //constructor

    //getters
    int getXPos() const{
        return xPos;
};
    int getYPos() const{
        return yPos;
    };
    float getFinalCost() const{
        return finalCost;
    };
    const std::shared_ptr<Node> &getParent() const{
        return parent;
    };
    float getGivenCost() const{
        return givenCost;
    };

    //setters
    void setXPos(int newXPos)
    {
        xPos = newXPos;
    };
    void setYPos(int newYPos)
    {
        yPos = newYPos;
    }

    ;
    void setFinalCost(float newFinalCost)
    {
        finalCost = newFinalCost;
    };
    void setParent(const std::shared_ptr<Node> &newParent)
    {
        parent = newParent;
    };
    void setGivenCost(float newGivenCost){
        givenCost = newGivenCost;
    };



private:
    int xPos;
    int yPos;
    float finalCost;
    float givenCost;
    std::shared_ptr<Node> parent;

};

class OrderByFinalCost
{
    public:
    bool operator()(const std::shared_ptr<Node> &s1, const std::shared_ptr<Node> &s2){
        return s1->getFinalCost() > s2->getFinalCost();
    }

};


#endif // NODE_H

