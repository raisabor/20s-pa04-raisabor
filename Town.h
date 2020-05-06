#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <fstream>


using namespace std;

class Town {
    private:
    
    float x;
    float y;
    float z;
    float weight;
    float ident;

    public:
    
    Town();
    Town(float , float , float , float);
    ~Town();
    
    Town(vector<float>);

    bool operator== (const Town&);
    friend ostream& operator<<(ostream&, const Town&);

    friend ofstream& operator<<(ofstream&, const Town&);
    
    float distanceTo(Town);
    static float distance(Town, Town);

    void setX(float);
    void setY(float);
    void setZ(float);
    void setWeight(float);
    void setIdent(float);


    float getX();
    float getY();
    float getZ();
    float getWeight();
    float getIdent();
    
    string print();

 
    
    


};


#endif // CITY_H

