//
//  Naive.h
//  Lab 4
//
//  Created by Richmond Aisabor on 11/10/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#ifndef Naive_h
#define Naive_h



#include <iostream>
#include "AdjacencyList.h"
#include "Town.h"
#include <vector>
#include <algorithm> //next_permuation() and  min() must be implemented
#include <cfloat>
#include <list>
#include "TourManager.h"


using namespace std;


class Naive {
    
private:
    // store all vertex apart from source vertex
    vector<int> vertice;

    
public:
    Naive();
   ~Naive();
    float shortestCycle(AdjacencyList graph);
    float min(float, float);
    
    
};

#endif /* Naive_h */
