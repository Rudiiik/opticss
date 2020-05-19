#ifndef FACTORY_H
#define FACTORY_H
#include "device.h"
#include "grid.h"
#include "slit.h"
#include "lens.h"
#include "iostream"
#include "vector" 

#endif // FACTORY_H
class Factory{
public:
    virtual Device* createDevice(const string& name) {
        if (name == "Grid") {
            return new Grid();
        }
        if (name == "Lens") {
            return new Lens();
        }
        if (name == "Slit"){
                return new Slit();
    }
    }
};
