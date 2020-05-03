#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string>


using namespace std;

class Town {
    private:
    
    float x;
    float y;
    float z;
    float ident;

    public:
    
    Town();
    Town(float , float , float , float);
    ~Town();
    
    Town(vector<float>);

    bool operator== (const Town&);
    friend ostream& operator<<(ostream&, const Town&);
    
    float distanceTo(Town);

    void setX(float);
    void setY(float);
    void setZ(float);
    void setIdent(float);


    float getX();
    float getY();
    float getZ();
    float getIdent();
    
    string print();

 
    
    


};


#endif // CITY_H

