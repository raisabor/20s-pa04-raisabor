#ifndef ALGORITHM_H
#define ALGORITHM_H



#include <iostream>

using namespace std;

enum metaheuristic {
    Brute = 0,
    Gene,
    
};

class Algorithm
{

public:
    virtual ~Algorithm(){};
    virtual void Load(string) = 0;
    virtual void Select(int) = 0;
	virtual void Execute() = 0;
    virtual void Display() = 0;
    virtual void Save(string) = 0;




};

#endif // ALGORITHM_H
