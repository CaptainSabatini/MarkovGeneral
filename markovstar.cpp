#include "markovstar.h"
#include <vector>

//////////////////////////////
//Resizes the star to the default length
//given by horizontal, Zoom, vertical, camera pos, and subjectChange
///////////////////////////////
MarkovStar::MarkovStar()
{
    myEdges.resize(6590);
    myIsChanged = false;
}

//////////////////////////////
//Resizes the star to a user defined length
//makes the star more general
//sets the seed so random psudorandom number can be used later
///////////////////////////////
MarkovStar::MarkovStar(const int size)
{
    myEdges.resize(size);
    myIsChanged = false;
}

//////////////////////////////
//Copy constructor
//////////////////////////////
MarkovStar::MarkovStar(std::vector<Node*> edges)
{
    myIsChanged = true;
    myEdges = edges;
}

//////////////////////////////
//If the id is valid insert edge
//  if the edge does not already exist create it with a node with 0 hits
//add the edge by incrementing the number of hits on that edge
//////////////////////////////
void MarkovStar::addEdge(Node* toAdd)
{
    int id = toAdd->getID();
    if(id > -1 && id < myEdges.size())
    {
        if(!myEdges[id])
        {
            myEdges[id] = new Node();
            Node* insert = toAdd;
            insert->setHits(0);
            myEdges[id]=insert;
        }
        myEdges[id]->hit();
        myIsChanged = true;
    }
}

//////////////////////////////
//Given a psudorandom chance (int)[0-100)
//returns a pointer to a node based on edges weighted chances
//////////////////////////////
Node* MarkovStar::getSuccess(float chance)
{
    Node* toReturn = NULL;
    if(myIsChanged)
        normalize();
    int i = 0;
    while(i<myEdges.capacity() && !toReturn)
    {
        if(myEdges[i])
        {
            if(chance < myEdges[i]->getChance())
            {
                toReturn = myEdges[i];
            }else{
                chance -= myEdges[i]->getChance();
            }//else
        }//if
        i++;
    }
    return toReturn;
}

//////////////////////////////
//Normalize the chances of each edge to be chosen
//normalize by giving everything a weight (myHits/totalHits) * 100
//*100 used to make the range (0-100] to associate with MarkovStar's [0-100)
//////////////////////////////
void MarkovStar::normalize()
{
    int totalHits = 0;
    for(int i=0; i<myEdges.capacity(); i++)
        if(myEdges[i])
            totalHits += myEdges[i]->getHits();
    if(totalHits ==0)
        totalHits = 1;
    for(int i=0; i<myEdges.capacity(); i++)
        if(myEdges[i])
            myEdges[i]->setChance((myEdges[i]->getHits()/(float)totalHits)*100);
    myIsChanged = false;
}

std::vector<Node*> MarkovStar::getStar()
{return myEdges;}
