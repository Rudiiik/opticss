#include "slit.h"
#include "device.h"
#include <iostream>
#include <fstream>
#include "parcer.h"
#include <cstdlib>
 
Slit::Slit() {}
LineOfSources Slit::ModifyLine(LineOfSources& prevLine) {
	/*for(int i = 0; i <= 4; i++){
	params.insert ( pair<string,double> ("d",0.01) );
	}*/

    double d = 0;
    double b = 0;
    double y = 0;

    char slit_params[50];
        ifstream fin("slit.txt");
        fin.getline(slit_params, 50);
        fin.close();
        cout << slit_params << endl;


        if(brkFind(slit_params, 3))
        {
            d = (double)atof(brkFind(slit_params, 1));//params["d"]; расстояние между щелями
            b = (double)atof(brkFind(slit_params, 2));//params["b"];  ширина щели
            y = (double)atof(brkFind(slit_params, 3));//params["y"];
        }

	LineOfSources line_to_modify(y, prevLine);
	LineOfSources newLine = line_to_modify;

	double x_0 = (1 - 2*b - d) / 2;

        std::cout << x_0 << std::endl;
            std::cout << x_0 / dSources << std::endl;
            std::cout << dSources / (x_0 + b) << std::endl;
            std::cout << dSources / (x_0 + b + d) << std::endl;



    for (int k = 0; k < (int)( x_0 / dSources); k++) {
                newLine.sources[k].amplitude = 0;
    };
    for (int k = (int)( (x_0 + b)/dSources); k < (int)((x_0 + b + d)/dSources); k++) {
        newLine.sources[k].amplitude = 0;
    };
    for (int k = (int)((x_0 + 2*b + d)/dSources); k < numberOfSources; k++) {
        newLine.sources[k].amplitude = 0;
    };



	return newLine;
}
