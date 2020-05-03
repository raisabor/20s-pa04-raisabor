//
//  Population.h
//  src
//
//  Created by Richmond Aisabor on 11/30/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#ifndef Population_h
#define Population_h

#include <iostream>
#include <vector>
#include "Tour.h"
#include "TourManager.h"


class Population
{
private:
    vector<Tour> tours;
    
    
public:

    Population(int, bool);
    ~Population();
    void saveTour(int, Tour);
    Tour& getTour(int);
    Tour getFittest();
    int sizeOfPopulation();
 
    
    
};

#endif /* Population_h */

