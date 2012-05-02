#include "node.h"

Node::Node()
{
    myID = -1;
    myHits = 0;
    myChance = 0;
}

Node::Node(int id, int hits, float chance)
{
    myID = id;
    myHits = hits;
    myChance = chance;
}

int Node::getID()
{return myID;}

int Node::getHits()
{return myHits;}

float Node::getChance()
{return myChance;}

void Node::setID(int id)
{myID = id;}

void Node::setHits(int hits)
{myHits = hits;}
void Node::setChance(float chance)
{myChance = chance;}
void Node::hit()
{myHits++;}
