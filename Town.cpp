#include  "Town.h"

Town::Town()
{
    this->ident = 0.0;
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
   
      
}

Town::Town(float i, float x, float y, float z)
{
    this->ident = i;
    this->x = x;
    this->y = y;
    this->z = z;
    

}

Town::~Town()
{
   
}




Town::Town(vector<float> cita)
{
    
     this->ident = cita.at(0);
     this->x = cita.at(1);
     this->y = cita.at(2);
     this->z = cita.at(3);

    
}

float Town::distanceTo(Town dest)
{
          float xDistance = abs(this->getX() - dest.getX());
          float yDistance = abs(this->getY() - dest.getY());
          float distance = sqrt((xDistance*xDistance) + (yDistance*yDistance));

    return distance;
}

void Town::setX(float x)
{
    this->x = x;
}

void Town::setY(float y)
{
    this->y = y;
}

void Town::setZ(float z)
{
    this->z = z;
}

void Town::setIdent(float i)
{
    this->ident = i;
}


float Town::getX()
{
    return x;
}

float Town::getY()
{
    return y;
}

float Town::getZ()
{
    return z;
}

float Town::getIdent()
{
    return ident;
}



bool Town::operator== (const Town& c1)
{
    if(this->x == c1.x &&  this->y == c1.y && this->z == c1.z && this->ident == c1.ident)
        return true;
    else
        return false;
}

 ostream& operator<<(ostream& os, const Town& c2)
{
   
    os << '(' << c2.ident << ',' << c2.x << ',' << c2.y << ',' << c2.z << ')';
    return os;
}

string Town::print()
{
    string actual;
    
    actual += to_string((int)this->ident) + " ";
    actual += to_string(printf("%.6g", this->x)) + " ";
    actual += to_string(printf("%.6g", this->y)) + " ";
    actual += to_string(printf("%.6g", this->z)) + " ";
    
    return actual;
   
}
