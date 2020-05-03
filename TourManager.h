//
//  TourManager.h
//  src
//
//  Created by Richmond Aisabor on 11/30/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#ifndef TourManager_h
#define TourManager_h

#include <iostream>
#include "Town.h"
#include <vector>


using namespace std;

class TourManager{
    
private:

   
    
public:
    static vector<Town> destinationTowns;
    TourManager();
    ~TourManager();
    static void addTown(Town);
    static Town getTown(int);
    static int getTownsCount();
    static void clear();
    static void display();
    
    
};

#endif /* TourManager_h */
