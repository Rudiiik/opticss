#ifndef LINEOFSOURCES_H
#define LINEOFSOURCES_H
#include "vector"
#include "lightsource.h"
#include "constants.h" 
#include "iostream"


using namespace std;

class LineOfSources
{
public:
    vector <Lightsource> sources;  //вектор из lightsource которы называется sources
    LineOfSources();
    LineOfSources(double amplitude, double phase, double y);
    LineOfSources(double new_y, const LineOfSources& prev_line);
    void Debug ();
    double GraphAmpl();
    double firstAmpl() const;
    double firstPh() const;
    pair<double,double> Graph(int i) const;
    string print();
    double MaxAmpl () const;
    
};


#endif // LINEOFSOURCES_H
