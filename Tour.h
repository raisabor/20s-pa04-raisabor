//
//  Tour.h
//  src
//
//  Created by Richmond Aisabor on 11/30/19.
//  Copyright © 2019 Richmond Aisabor. All rights reserved.
//

#ifndef Tour_h
#define Tour_h

#include <iostream>
#include <vector>
#include "Town.h"
#include "TourManager.h"
#include <algorithm>
#include<iterator>
#include <string>
#include <fstream>


class Tour{
    
private:
    
    vector<Town> cycle;
    float distance;
    float fitness;
    
public:
    Tour();
    Tour(vector<Town>);
    Tour(const Tour&);
    ~Tour();
    Tour& operator=(const Tour&);
    void generateTour();
    Town getTown(int);
    void setTown(int, Town);
    float getFitness();
    float getDistance();
    int sizeOfTour() const;
    bool containsTown(Town);
    void random_shuffle(vector<Town>&);
    void print();
    void printF(ofstream&);
};

#endif /* Tour_h */

