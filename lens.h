#ifndef LENS_H
#define LENS_H
#include "device.h"

class Lens : public Device
{

public:
	Lens();
	LineOfSources ModifyLine(LineOfSources& prevLine);
	//LineOfSources::LineOfSources(double y, const LineOfSources& prevLine);
	vector <string> showParams() {
		return{"y", "f" };
	}
};
  
#endif // GRID_H
