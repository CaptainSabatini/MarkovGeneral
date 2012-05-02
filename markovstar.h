#ifndef MARKOVSTAR_H
#define MARKOVSTAR_H
#include "node.h"
#include <vector>

class MarkovStar
{
private:
    std::vector<Node*> myEdges;
    bool myIsChanged;
    void normalize();
public:
    MarkovStar();
    MarkovStar(const int size);
    MarkovStar(std::vector<Node*> edges);
    void addEdge(Node* toAdd);
    Node* getSuccess(float chance);
    std::vector<Node*> getStar();
};

#endif // MARKOVSTAR_H
