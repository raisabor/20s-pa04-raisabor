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



using namespace std;

class Search : public Algorithm
{
private:
    
    
	bool* selection;
    vector<Town>* vec1;
	double* timeSpan;
    list<int>* holder;
    float* holder2;

  
    



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
