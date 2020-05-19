#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

double myAtan(double x, double y);

class Lightsource
{ 
//private:

public:
    double phase;
    double x;
    double y;
    double amplitude;
    Lightsource();
    Lightsource(double _amplitude, double _phase, double _x, double _y);
    Lightsource operator+=(const Lightsource& b);
    void Debug ();
    
    double ReturnX () const;
        double ReturnAmpl() const;
        double ReturnPh() const;
};

#endif // LIGHTSOURCE_H
