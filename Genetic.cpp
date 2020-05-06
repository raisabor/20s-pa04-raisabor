//
//  Genetic.cpp
//  src
//
//  Created by Richmond Aisabor on 12/2/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#include "Genetic.h"

const float Genetic:: mutationRate = 10; //treated as a percentage
const int Genetic:: tournamentSize = 5;


Population Genetic:: run(Population poppy)
{
     Population* newPopulation = new Population(poppy.sizeOfPopulation(), false);
    
   
    
    for (int i = 0; i < newPopulation->sizeOfPopulation(); i++)
           {
               //selection
               Tour parent1 = tournamentSelection(poppy);
               Tour parent2 = tournamentSelection(poppy);

               //crossover
               Tour child = crossover(parent1, parent2);

               //create new population
               newPopulation->saveTour(i, child);
           }

           //mutate new population
           for (int i = 0; i < newPopulation->sizeOfPopulation(); i++)
           {
               mutate(newPopulation->getTour(i));
           }



           Population populis =  *newPopulation;

           delete newPopulation;


    return populis;
    
}

Tour Genetic:: crossover(Tour parent1, Tour parent2)
{

    //create the new child
           Tour* child = new Tour();
           Town dummyTown;

           //get start and end sub tour positions for parents1's tour
           int startPos = rand() % parent1.sizeOfTour();
           int endPos = rand() % parent1.sizeOfTour();

           // Loop and add the sub tour from parent1 to our child
           for (int i = 0; i < child->sizeOfTour(); i++)
           {
               // if our start position is less than the end position
               if (startPos < endPos && i > startPos && i < endPos)
               {
                   child->setTown(i, parent1.getTown(i));
               } // If our start position is larger
               else if (startPos > endPos)
               {
                   if (!(i < startPos && i > endPos))
                   {
                       child->setTown(i, parent1.getTown(i));
                   }
               }
           }

           // Loop through parent2's city tour
           for (int i = 0; i < parent2.sizeOfTour(); i++)
           {
               // If child doesn't have the city add it
               if (!child->containsTown(parent2.getTown(i)))
               {
                   // Loop to find a spare position in the child's tour
                   for (int ii = 0; ii < child->sizeOfTour(); ii++)
                   {
                       // Spare position found, add city
                       // CHECK HERE!
                       if (child->getTown(ii).getX() == dummyTown.getX() && child->getTown(ii).getY() == dummyTown.getY()&& child->getTown(ii).getZ() == dummyTown.getZ())
                       {
                           child->setTown(ii, parent2.getTown(i));
                           break;
                       }
                   }
               }
           }


            Tour newChild = *child;
            delete child;

    return newChild;

}


void Genetic:: mutate(Tour torey)
{
    
    // Loop through tour cities
    for(int tourPos1=0; tourPos1 < torey.sizeOfTour(); tourPos1++)
    {
        // Apply mutation rate
        int mutation = rand() % 100 + 1; // random number in [1,100]

        if(mutation <= Genetic::mutationRate) // checks if the random number <= mutation rate
        {
            // Get a second random position in the tour
            int tourPos2 =  rand() % torey.sizeOfTour() ;

            // Get the cities at target position in tour
            Town town1 = torey.getTown(tourPos1);
            Town town2 = torey.getTown(tourPos2);

            // Swap them around
            torey.setTown(tourPos2, town1);
            torey.setTown(tourPos1, town2);
        }
    }
    
}


Tour Genetic:: tournamentSelection(Population poppy)
{
    // Create a tournament population
    Population* tournament = new Population(tournamentSize, false);


    // For each place in the tournament get a random candidate tour and
    // add it
    for (int i = 0; i < tournamentSize; i++)
    {
        int randomId = rand() % poppy.sizeOfPopulation();
        tournament->saveTour(i, poppy.getTour(randomId));
    }

    // Get the fittest tour
    Tour fittest = tournament->getFittest();

    return fittest;
    
    
}
