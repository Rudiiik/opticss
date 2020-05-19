#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "lineofsources.h"
#include <fstream>


int main(int argc, char *argv[])
{
 
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    
    std::cout << "Hi, poor user of this program:)" << std::endl;
    
    double A = 1;
    double Ph = 1.57;
    double Y = 0;
    
    LineOfSources line(0, Ph, Y);

    
    LineOfSources final_line(1.0, line);
 //   final_line.Debug();
    
    


    ofstream file;
    file.open("data.txt");
    file << final_line.print();

     return a.exec();
}
