//#pragma once
#ifndef SLIT_H
#define SLIT_H
#include "device.h"

class Slit : public Device
{ 

public:
	Slit();
	LineOfSources ModifyLine(LineOfSources& prevLine);
	//LineOfSources::LineOfSources(double y, const LineOfSources& prevLine);
	vector <string> showParams() {
		return{ "y","d", "b" };
	}
};

#endif // SLIT_H


