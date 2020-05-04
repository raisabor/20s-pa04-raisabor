#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <iostream>
#include <vector>
#include <list> 
#include <iterator>
#include "Town.h"
using namespace std;


template <typename P>

class AdjNode
{

private:
    P data;
    


public:
    vector<P> edges;
  
    AdjNode();
    AdjNode(P val);
    bool operator==(const AdjNode<P>&);
    P& getData();


};

template <typename P>
AdjNode<P>::AdjNode()
{
    data = 0;
    
}




template <typename P>
AdjNode<P>::AdjNode(P val)
{

    data = val;

}

template <typename P>
P& AdjNode<P>::getData()
{

    return data;

}



template <typename P>
bool AdjNode<P>::operator==(const AdjNode<P>& Aj)
{
    if(this->data == Aj.data)
        return true;
     else
        return false;


}


class AdjacencyList
{


public:
    vector<AdjNode<Town>> graph1;
    AdjacencyList();
    ~AdjacencyList();
    void insertFor(Town&, Town&);
    vector<Town>& find(Town);
    void printList();
    //overloaded brackets operator
  
};

#endif // ADJANCENCYLIST_H
