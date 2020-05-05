#ifndef SEARCH_H
#define SEARCH_H


#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <chrono>
#include <vector>
#include <tuple>
#include <variant>
#include "Algorithm.h"
#include <list>
#include "Town.h"
#include "TourManager.h"
#include "Population.h"
#include "Tour.h"
#include "Genetic.h"
#include "AdjacencyList.h"
#include "Naive.h"



using namespace std;

class Search : public Algorithm
{
private:

    Naive salesMan;
    bool selection[4];
    vector<Town> vec1;
    float holder;
    float holder1;
    float holder2;
    list<float> holder4;
    AdjacencyList ajay;
    Tour solution;




public:
    Search();
    ~Search();
    void Load(string);
    void Execute();
    void Display();
    void Stats();
    void Select(int);
    void Save(string);
    // void Configure(); future expandability



};

#endif // SEARCH_H
