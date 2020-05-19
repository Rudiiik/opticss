#include "grid.h"
#include "device.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QString>
#include "parcer.h"
 

Grid::Grid(){}


LineOfSources Grid::ModifyLine ( LineOfSources& prevLine  ) {

    char grid_params[50];
        ifstream fin("grid.txt");
        fin.getline(grid_params, 50);
        fin.close();
        cout << grid_params << endl;

    double d = 0;
    double N = 0;
    double b = 0;
    double lx = 0;
    double y = 0;

   // std::cout << "vvedite d, N, b, lx, y" << std::endl;
    //std::cin >> d >> N >> b >> lx >> y;

    /*for(int i = 0; i <= 4; i++){
        params.insert ( pair<string,double> ("d",0.01) );
    }*/

        if(brkFind(grid_params, 5))
        {
             d = (double)atof(brkFind(grid_params, 1));// params["d"];
             N = (double)atof(brkFind(grid_params, 2));//params["N"];
             b = (double)atof(brkFind(grid_params, 3));//params["b"];
             lx = (double)atof(brkFind(grid_params, 4));//params["lx"];
             y = (double)atof(brkFind(grid_params, 5)); // координата по y*/
        }

	LineOfSources line_to_modify(y, prevLine);
	LineOfSources newLine = line_to_modify;

    for(int k = 0; k < numberOfSources; k ++){
        for (int i = 0; i < N; i++){
            if (lx + i*d <= newLine.sources[k].x && lx + b + i*d >= newLine.sources[k].x ){
                newLine.sources[k].amplitude = 0;
            }
        }
    }

    return newLine;
}
// LineOfSources ModifyLine (LineOfSources prevLine){
        /* вычисляем на уровне Y значение теущей линии источников; потом ищем расстояние между источниками l; цикл из N итераций внутри него (d-b)/l
         * раз зануляем амлитуду и b/l раз ничего не трогаем. Все начинаем с X и считаем что решетка начинается с темной полосы*/
