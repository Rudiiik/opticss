#include "lightsource.h"
#include "math.h"
#include "iostream"
#include "constants.h"
 
using namespace std;


Lightsource::Lightsource(double _amplitude, double _phase, double _x, double _y){
    amplitude = _amplitude;
    phase = _phase;
    x = _x;
    y = _y;
}

Lightsource Lightsource::operator+=(const Lightsource& b) {
    double r = sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
    double b_amplitude = b.amplitude / r;
    double new_phase = b.phase + 2 * pi * (r / lambda);
    double dx = (amplitude * sin(phase) + b_amplitude * sin(new_phase));
    double dy = (amplitude * cos(phase) + b_amplitude*cos(new_phase));
    double res_phase = myAtan(dx, dy);
    //double res_phase = atan(dx/dy);
    double res_amplitude = sqrt((amplitude*amplitude + b_amplitude*b_amplitude
                                 + 2*amplitude*b_amplitude * cos(phase - new_phase)));
    if (res_amplitude < 0.00001) {
        res_phase = 0;
    }
    amplitude = res_amplitude;
    phase = res_phase;
    return *this;
}

void Lightsource::Debug () {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "ampl = " << amplitude << endl;
    cout << "phase = " << phase << endl;
}
double myAtan(double x, double y)
{
    int mark1 = 0;
    int mark2 = 0;
    if (y >= x)
    {
        mark1 = 1;
    }
    if (y >= -x)
    {
        mark2 = 1;
    }
    
    if (mark1 == 1)
    {
        if (mark2 == 1)
        {
            return pi/2 - atan(x/y);
        }
        else
        {
            return (pi + atan(y/x));
        }
    }
    else
    {
        if (mark2 == 1)
        {
            return atan(y/x);
        }
        else
        {
            return 3 * pi/2 - atan(x/y);
        }
    }
    
};


double Lightsource::ReturnX() const {
    return x;
};

double Lightsource::ReturnAmpl() const {
    return amplitude;
};
double Lightsource::ReturnPh() const {
    return phase;
};
