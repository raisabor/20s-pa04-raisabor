//
//  TourManager.cpp
//  src
//
//  Created by Richmond Aisabor on 11/30/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#include "TourManager.h"


vector<Town> TourManager:: destinationTowns;

TourManager:: TourManager()
{

}


TourManager:: ~TourManager()
{

}

void TourManager::addTown(Town town)
{
    //if(destinationTowns.size() < 9)
         destinationTowns.push_back(town);
}

Town TourManager:: getTown(int index)
{
    return (Town)destinationTowns.at(index);
}

int TourManager:: getTownsCount()
{
    return (int)destinationTowns.size();
}

void TourManager:: clear()
{
    destinationTowns.clear();
}

void TourManager:: display(){
    
    for(int i=0; i< destinationTowns.size(); i++)
    {
        cout << destinationTowns[i] << ' ';
    }
}
