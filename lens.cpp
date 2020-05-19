#include "lens.h"

#include "device.h"
#include "math.h"
#include "device.h"
#include <math.h>
  

Lens::Lens() {}
LineOfSources Lens::ModifyLine(LineOfSources& prevLine) {
	/*for(int i = 0; i <= 4; i++){
	params.insert ( pair<string,double> ("d",0.01) );
	}*/
    double f = 0.1;// params["d"]; фокусное рассояние
    double y = 0.6;//params["y"];

	LineOfSources line_to_modify(y, prevLine);
	LineOfSources newLine = line_to_modify;

//    double R = f * 0.4; // радиус кривизны
//	double x_0 = max_x - min_x;


	for (int k = 0; k < numberOfSources; k++) {
        //	double b = sqrt(4 * R*R - x_0*x_0 + 4 * x_0*newLine.sources[k].x - 4 * newLine.sources[k].x*newLine.sources[k].x);
        newLine.sources[k].phase = 0;
        //	newLine.sources[k].phase += (pi * 0.5 * (b - sqrt(b*b - 4*newLine.sources[k].x*(x_0 - newLine.sources[k].x)))/lambda);

	}

	return newLine;
}
