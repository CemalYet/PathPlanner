#include "node.h"

Node::Node(int xPos, int yPos, float finalCost,float givenCost, const std::shared_ptr<Node> &parent) : xPos(xPos),
    yPos(yPos),
    finalCost(finalCost),
    givenCost(givenCost),
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

void Node::setGivenCost(float newGivenCost)
{
    givenCost = newGivenCost;
}


