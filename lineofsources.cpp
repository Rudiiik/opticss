#include "lineofsources.h"
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>


 
LineOfSources::LineOfSources()
{

}
LineOfSources::LineOfSources( double _amplitude, double _phase, double _y){
    for(int i = 0; i < numberOfSources; i ++){
        double _x = min_x + i * ( (max_x-min_x) / (numberOfSources - 1));
        sources.push_back(Lightsource(_amplitude, _phase, _x, _y));
    }
}
LineOfSources::LineOfSources(double new_y, const LineOfSources& prev_line){
    for(int i = 0; i < numberOfSources; i ++){
        double _x = min_x + i * ( (max_x-min_x) / (numberOfSources - 1));
        sources.push_back(Lightsource(0, 0, _x, new_y));
        for (int k = 0; k < numberOfSources; k++){
           sources[i] += prev_line.sources[k];
        }
    }

    auto m = MaxAmpl();
    for (auto& s : sources) {
        s.amplitude /= m;
    }
}

void LineOfSources::Debug () {
    
    for (int i = 0; i < numberOfSources; i ++) {
        sources[i].Debug();
    }
    cout << "----------------------------------------" << endl;
}

string LineOfSources::print()
{
    string result;
    for (int i = 0; i < numberOfSources; i++)
    {
        string _ampl;
        string _x;
        double a = sources[i].ReturnAmpl();
        double b = sources[i].ReturnX();
        result += std::to_string(a) + "," + std::to_string(b) + "\n";
    }
    return result;
};

pair<double,double> LineOfSources::Graph(int i) const{
    pair<double, double> a;
    a.first = sources[i].ReturnX();
    a.second = sources[i].ReturnAmpl();
    return a;
}


double LineOfSources::firstAmpl() const{
    return sources[0].ReturnAmpl();
};

double LineOfSources::firstPh() const{
    return sources[0].ReturnPh();
};

double LineOfSources::MaxAmpl() const{
    double MaxAmpl = 0 ;
    for (int k = 0; k < numberOfSources; k++){
        if (sources[k].ReturnAmpl() >= MaxAmpl) {
            MaxAmpl = sources[k].ReturnAmpl();
        };
    };
    return MaxAmpl;
};


