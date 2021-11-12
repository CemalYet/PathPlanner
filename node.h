#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <memory>


class Node
{
public:
    //constructor
    Node(int xPos, int yPos, float finalCost, const std::shared_ptr<Node> &parent);
    bool operator<(std::shared_ptr<Node> &nodeTwo) const;
    bool operator>(std::shared_ptr<Node> &nodeTwo) const;


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
    }
;
    //setters
    void setXPos(int newXPos);
    void setYPos(int newYPos);
    void setFinalCost(float newFinalCost);
    void setParent(const std::shared_ptr<Node> &newParent);

private:
    int xPos;
    int yPos;
    float finalCost;
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
