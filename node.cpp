#include "node.h"

Node::Node(int xPos, int yPos, float finalCost, const std::shared_ptr<Node> &parent) : xPos(xPos),
    yPos(yPos),
    finalCost(finalCost),
    parent(parent)
{}

void Node::setXPos(int newXPos)
{
    xPos = newXPos;
}

void Node::setYPos(int newYPos)
{
    yPos = newYPos;
}

void Node::setFinalCost(float newFinalCost)
{
    finalCost = newFinalCost;
}

void Node::setParent(const std::shared_ptr<Node> &newParent)
{
    parent = newParent;
}
bool Node::operator<(std::shared_ptr<Node> &nodeTwo) const{
    return this->finalCost < nodeTwo->finalCost;
}
/*
bool Node::operator>(std::shared_ptr<Node> &nodeTwo) const{
    return this->finalCost > nodeTwo->finalCost;
}
*/
