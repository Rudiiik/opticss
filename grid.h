#ifndef GRID_H
#define GRID_H
#include "device.h"

class Grid: public Device
{ 

public:
    Grid();
    LineOfSources ModifyLine ( LineOfSources& prevLine);
    //LineOfSources::LineOfSources(double y, const LineOfSources& prevLine);
    vector <string> showParams(){
        return {"lx", "y", "N", "d", "b"};
    }
};

#endif // GRID_H
