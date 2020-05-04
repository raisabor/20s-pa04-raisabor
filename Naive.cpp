//
//  NaiveTSP.cpp
//  Lab 3
//
//  Created by Richmond Aisabor on 11/10/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#include "Naive.h"

Naive::Naive()
{

}

Naive::~Naive()
{

}


list<int> Naive::shortestCycle(AdjacencyList graph, int count)
{


       for (int i = 0; i < 9; i++)
       {
           if (i != count)
           {
               vertice.push_back(i);
           }
       }
    
            float minPath = FLT_MAX;  // store minimum weight Hamiltonian Cycle.
    
       do {
     
           // store current Path weight(cost)
           float currentDistance = 0.0;
             
           // compute current distance
           int k = count;
           
           for (int i = 0; i < vertice.size(); i++) {
               currentDistance += graph.graph1[k].edges[vertice[i]].getWeight();
               k = vertice[i];
           }
           currentDistance += graph.graph1[k].edges[count].getWeight();
     
           // update minimum
           minPath = Naive::min(minPath, currentDistance);
            
       } while (next_permutation(vertice.begin(), vertice.end()));
     
    return getOptPath();
    
}


float Naive::min(float x ,float y)
{
    int z = 0;
    if(x < y)
    {
        z = x;
        calcPath(vertice);
        
    }
    
    
    return z;
    
    
}

void Naive::calcPath(vector<int> path)
{
    
    
    for(int u = 0; u < path.size(); u++)
    {
        path[u]++;
    }
     
    
    list<int> dest(path.begin(), path.end());
    
    
    dest.push_front(1);
    dest.push_back(1);
    
    optPath = dest;
    
    
}

list<int> Naive::getOptPath()
{
    return optPath;
}



//graph.graph1[k].getData().[vertex[i]].getWeight();
           
