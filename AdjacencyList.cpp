#include "AdjacencyList.h"


AdjacencyList::AdjacencyList()
{
    
}

AdjacencyList::~AdjacencyList()
{
   
}


void AdjacencyList::insertFor(Town& src, Town& dest) //associates each vertex in the graph with a collection of its neighboring edges
{

    //calculate weight between cities
    
     dest.setWeight(Town::distance(src, dest));
     src.setWeight(0.0);
    
    
    bool found = false;
    for(int i=0; i<graph1.size(); i++)
    {
        if(graph1[i].getData() == src)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        AdjNode<Town> temp(src);
        graph1.push_back(temp);
        graph1[graph1.size()-1].edges.push_back(dest);
        
        
    }
    else
    {
        int holder = 0;
        for(int i=0; i<graph1.size(); i++)
        {
            if(graph1[i].getData() == src)
            {
                holder = i;
            }
        }

        graph1[holder].edges.push_back(dest);
    }


}


vector<Town>& AdjacencyList::find(Town cita)
{
    AdjNode<Town> temp(cita);

 for(int v = 0; v < graph1.size(); v++)
 {

   if(graph1[v] == temp)
   {
       return graph1[v].edges;
   }

 }
 throw exception();
}

void AdjacencyList::printList()
{

    for(int i = 0; i < graph1.size(); i++)
    {
		cout << graph1[i].getData();
         cout << "-> ";

        for(int z = 0; z < graph1[i].edges.size(); z++)
        {
			cout << graph1[i].edges[z];
             cout << "-> ";

         }
          cout << endl;

    }


}


