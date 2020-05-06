//
//  Genetic.h
//  src
//
//  Created by Richmond Aisabor on 12/2/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#ifndef Genetic_h
#define Genetic_h

#include <iostream>
#include "Population.h"
#include "Tour.h"
#include "Town.h"
#include <cstdlib>

class Genetic
{
    
private:
    static const float mutationRate;
    static const int tournamentSize;
    
public:
    static Population run(Population);
    static Tour crossover(Tour, Tour);
    static void mutate(Tour);
    static Tour tournamentSelection(Population);
    
    
};

#endif /* Genetic_h */
