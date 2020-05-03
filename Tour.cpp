//
//  Tour.cpp
//  src
//
//  Created by Richmond Aisabor on 11/30/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#include "Tour.h"


Tour::Tour()
{
    distance = 0.0;
    fitness = 0.0;
   
    Town dummy;

    cycle.resize(TourManager::getTownsCount(), dummy);

   
    
}


Tour::Tour(vector<Town> other)
{
    
    this->cycle.clear();
    for(int i = 0; i < other.size(); i++)
    {

        this->cycle.push_back(other.at(i));
    }
    
    distance = 0.0;
    fitness = 0.0;
}

Tour:: Tour(const Tour& other)
{
    
       this->distance = other.distance;
       this->fitness = other.fitness;
       this->cycle.clear();
       for(int i = 0; i < other.cycle.size(); i++)
       {

           this->cycle.push_back(other.cycle.at(i));
       }
    
    
}

Tour:: ~Tour()
{

    
}


Tour& Tour::operator=(const Tour& other)
{


    if(this == &other)
    {
        return *this;
    }else{

        this->distance = other.distance;
        this->fitness = other.fitness;
        this->cycle.clear();
        for(int i = 0; i < other.sizeOfTour(); i++)
        {

            this->cycle.push_back(other.cycle.at(i));
        }
    }

    return *this;


}




void Tour:: generateTour()
{
    //loop through all our destinations cities and add them to our tour
    for (int i = 0; i < TourManager::getTownsCount(); i++)
    {
        this->setTown(i, TourManager::getTown(i));
    }
    //randomly reorder the tour
    random_shuffle(cycle);
    
}

Town Tour:: getTown(int index)
{
    return (Town)cycle.at(index);
    
}

void Tour:: setTown(int index, Town town)
{
    cycle[index] = town;

   //if the tour has been altered we need to reset fitness and distance
   fitness = 0.0;
   distance = 0.0;
    
}

//gets the tours fitness
float Tour:: getFitness()
{
    if (this->fitness == 0.0)
    {
        this->fitness = 1/getDistance();
    }

    return this->fitness;
}

float Tour:: getDistance()
{
    if(this->distance == 0.0)
    {
        float tempDistance= 0.0;
        
        for(int i = 0; i < sizeOfTour(); i++)
        {
            Town startTown = getTown(i);
            
            Town* destinyTown = new Town();
            
            if(i+1 < sizeOfTour())
            {
                *destinyTown = getTown(i+1);
            }
            else
            {
                *destinyTown = getTown(0);
            }
            // Get the distance between the two cities
            tempDistance += startTown.distanceTo(*destinyTown);
            delete destinyTown;
        }
        distance = tempDistance;
    }
    
    return distance;
}


int Tour:: sizeOfTour() const
{
    return (int)cycle.size();
}

// Check if the tour contains a city
bool Tour:: containsTown(Town town)
{
       for(int i = 0; i < sizeOfTour(); i++)
       {
         if( (cycle[i].getX() == town.getX()) && (cycle[i].getY() == town.getY()) )
         {
             return true;
         }
               
       }
    
       return false;
}

void Tour:: random_shuffle(vector<Town>& township)
{
    size_t n = township.size();
    
    for(int i = 0; i < n - 1; i++)
    {
        int j = i + rand() % (n - i);
        std::swap(township[i], township[j]);
    }

           
}

void Tour:: print()
{
    
    for (int i = 0; i < cycle.size(); i++)
    {
        cout << cycle[i] << endl;
                
    }
       

}

