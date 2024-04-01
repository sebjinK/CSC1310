#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>

using namespace std;

class GraphList
{
    private:
        struct ListNode
        {
            int value;
            ListNode * next;
        };
        ListNode ** headArray;
        int numVertices;
        int numEdges;

    public:
        GraphList(int/*num of vertices in graph*/);
        ~GraphList();
        void addEdge();
        void printGraph();
};

GraphList::GraphList(int numVertices)
{

}
GraphList::~GraphList()
{

}
void GraphList::addEdge()
{

}
void GraphList::printGraph()
{

}

#endif