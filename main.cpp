#include "markovchain.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char *argv[])
{
    srand ( time(NULL) );
    MarkovChain newChain = MarkovChain();
    cout << "Hello" << endl;
    for(int i(0); i<30000; i++)
    {
        int parent = rand()%6590;
        int child = rand()%6590;
        newChain.addEdge(parent, new Node(child, 3, .2));
    }
    Node* buddy[100];
    for(int i(0); i<100; i++)
        buddy[i] = new Node();
    newChain.getSuccess(0);
    for(int i(0); i<100; i++)
    {
        int parent = rand()%6590;
        while(!newChain.isSuccessor(parent))
        {
            parent = rand()%6590;
        }
        buddy[i] = newChain.getSuccess(parent);
    }
    std::vector<Node*> aGuy = newChain.getAllSuccessor(0);
    for(int i(0); i<100; i++)
    {
        while(!aGuy[i])
            i++;
        if(i<aGuy.size())
            cout << aGuy[i]->getID() << endl;
    }
    cout << "Press <Return> to exit." << endl;
    cin.ignore();
    cin;
}
