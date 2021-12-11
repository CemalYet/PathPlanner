#include "node.h"

//Node::Node(int xPos, int yPos, float finalCost, float givenCost, const std::shared_ptr<Node> &parent) : xPos(xPos),
//    yPos(yPos),
//    finalCost(finalCost),
//    givenCost(givenCost),
//    parent(parent)
//{}

Node::Node(int xPos, int yPos, float givenCost, const std::shared_ptr<Node> &parent) : xPos(xPos),
    yPos(yPos),
    givenCost(givenCost),
    parent(parent)
{}

//Node::Node(int xPos, int yPos, const std::shared_ptr<Node> &parent) : xPos(xPos),
//    yPos(yPos),
//    parent(parent)
//{}
