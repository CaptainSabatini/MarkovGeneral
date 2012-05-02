#ifndef MARKOVCHAIN_H
#define MARKOVCHAIN_H
#include "markovstar.h"
#include <vector>
using namespace std;

class MarkovChain
{
private:
    std::vector<MarkovStar*> myChain;
    int mySize;
public:
    MarkovChain();
    MarkovChain(const int size);
    void addEdge(int parent, Node* toAdd);
    Node* getSuccess(int parent);
    bool isSuccessor(int parent);
    std::vector<Node*> getAllSuccessor(const int parent);
};

#endif // MARKOVCHAIN_H
