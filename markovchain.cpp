#include "markovchain.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////
//Resizes the chain to the default length
//given by horizontal, Zoom, vertical, camera pos, and subjectChange
//sets the seed so random psudorandom number can be used later
///////////////////////////////
MarkovChain::MarkovChain()
{
    myChain.resize(6590);
    /* initialize random seed: */
    srand(time(NULL));
}

//////////////////////////////
//Resizes the chain to user specified length
//Makes the Markov Chain more general
//sets the seed so random psudorandom number can be used later
///////////////////////////////
MarkovChain::MarkovChain(const int size)
{
    myChain.resize(size);
    /* initialize random seed: */
    srand(time(NULL));
}
//////////////////////////////
//If there are no edges for this part of the chain then create a new star with the same size as the chain
//if the parent id is valid, add the edge from parent to toAdd
//////////////////////////////
void MarkovChain::addEdge(int parent, Node* toAdd)
{
    if(!myChain[parent])
        myChain[parent] = new MarkovStar(myChain.size());
    //valid
    if(toAdd->getID() > -1  && toAdd->getID() < myChain.size())
    {

        myChain[parent]->addEdge(toAdd);
    }
}
//////////////////////////////
//If parent is valid get the successor based on a weighted chance
//the chance roll is generated here
//I used [0,100) because it was more precise that getting (0-1]
//////////////////////////////
Node* MarkovChain::getSuccess(int parent)
{
    float chance = rand()%100;
    Node* toReturn = new Node();
    //Don't fall off the vector
    if(parent >-1 && parent < myChain.size())
        if(isSuccessor(parent))
            toReturn = myChain[parent]->getSuccess(chance);
    return toReturn;
}

bool MarkovChain::isSuccessor(int parent)
{return myChain[parent];}

//////////////////////////////
//If the parent exists return the associated star (could be size 0 vector)
//if not return size 0 vector
//////////////////////////////
std::vector<Node*> MarkovChain::getAllSuccessor(const int parent)
{
    std::vector<Node*> toReturn;
    toReturn.resize(0);
    if(parent > -1 && parent < myChain.size())
        toReturn = myChain[parent]->getStar();
    return toReturn;
}
