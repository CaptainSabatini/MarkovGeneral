#ifndef NODE_H
#define NODE_H

class Node
{

private:
    int myID;
    int myHits;
    float myChance;
public:
    Node();
    Node(int id, int hits, float chance);
    int getID();
    int getHits();
    float getChance();
    void setID(int id);
    void setHits(int hits);
    void setChance(float chance);
    void hit();
};

#endif // NODE_H
