//
//  Population.cpp
//  src
//
//  Created by Richmond Aisabor on 11/30/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#include "Population.h"



Population:: Population(int size, bool init)
{

    tours.resize(size);

    if(init)
    {
        for (int i = 0; i < size; ++i)
        {
            Tour* newTour = new Tour();
            newTour->generateTour();
            saveTour(i, *newTour);
        }
    }
}

Population:: ~Population()
{

}




void Population:: saveTour(int index, Tour tour)
{
    tours[index] = tour;
    
}

// Gets a tour from population
Tour& Population:: getTour(int index)
{
       return tours[index];
    
}

//best tour in the population
Tour Population::getFittest()
{
     Tour fit = tours[0];

       // Loop through each tour to find fittest
       for (int i = 1; i < sizeOfPopulation(); i++)
       {
           if (fit.getFitness() <= getTour(i).getFitness())
           {
               fit = getTour(i);
           }
       }
       return fit;
}

//population size
int Population::sizeOfPopulation()
{
       return (int) tours.size();
}




