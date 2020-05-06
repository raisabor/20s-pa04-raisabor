//
//  NaiveTSP.cpp
//  Lab 3
//
//  Created by Richmond Aisabor on 11/10/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#include "Naive.h"
#define V 12

Naive::Naive()
{

}

Naive::~Naive()
{

}


float Naive::shortestCycle(AdjacencyList graph)
{



       for (int i = 0; i < V; i++)
       {
           if (i != 0)
           {
               vertice.push_back(i);
           }
       }
    
            float minPath = FLT_MAX;  // store minimum weight Hamiltonian Cycle.
    
       do {
     
           // store current Path weight(cost)
           float currentDistance = 0.0;
             
           // compute current distance
           int k = 0;

           for (int i = 0; i < vertice.size(); i++) {
               currentDistance += graph.graph1[k].edges[vertice[i]].getWeight();
               k = vertice[i];
           }
           currentDistance += graph.graph1[k].edges[0].getWeight();

     
           // update minimum
           minPath = Naive::min(minPath, currentDistance);
            
       } while (next_permutation(vertice.begin(), vertice.end()));
     
    return minPath;
    
}


float Naive::min(float x ,float y)
{
    float z = x;

    if(x > y)
    {
        z = y;
        
    }

    return z;
    
    
}

           
