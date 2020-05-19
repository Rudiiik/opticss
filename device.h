#ifndef DEVICE_H
#define DEVICE_H
#include "lineofsources.h"
#include "string"
#include "map"
#include <iostream> 

using namespace std;

class Device
{
public:
    map <string, double> params;
    Device();

    virtual vector <string> showParams() =0; // метод возвращает вектор
    void setParam(string name, double value); //
    virtual LineOfSources ModifyLine ( LineOfSources& prevLine) = 0;

};

#endif // DEVICE_H
