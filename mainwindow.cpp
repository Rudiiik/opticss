#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lineofsources.h"
#include "lightsource.h"
#include "constants.h"
#include "device.h"
#include "grid.h" 
#include "slit.h"
#include "lens.h"
#include "factory.h"
#include "vector"
#include <iostream>
#include <fstream>
#include <QFile>
#include "parcer.h"
using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) // нужно прописать х и A^2
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<Device*> devices;

void MainWindow::on_pushButton_clicked() // кнопка
{ 

     //vector<double> _params {d, N, b, lx, y};
    LineOfSources line(A, Ph, Y);
    Factory f;
   // line.Debug();

        Device* grid = f.createDevice("Grid");
        Device* slit = f.createDevice("Slit");


        char slit_params[50];
            ifstream fin("slit.txt");
            fin.getline(slit_params, 50);
            fin.close();
            cout << slit_params << endl;

            double grid_y = 0;
            double slit_y = 0;

            if (brkFind(slit_params, 3))
            {
                slit_y = (double)atof(brkFind(slit_params, 3));//params["y"];
            }

        char grid_params[50];
            ifstream fin1("grid.txt");
            fin1.getline(grid_params, 50);
            fin1.close();
            cout << grid_params << endl;

            if(brkFind(grid_params, 5))
            {
                grid_y = (double)atof(brkFind(grid_params, 5)); // координата по y*/
            }
        LineOfSources final (0, line);
        if (grid_y != 0 && slit_y != 0){
        if (grid_y < slit_y){
            LineOfSources curr_line = grid->ModifyLine(line);
            LineOfSources curr_line1 = slit->ModifyLine(curr_line);
            final = LineOfSources(1, curr_line1);
        }
        else {
            LineOfSources curr_line = slit->ModifyLine(line);
            LineOfSources curr_line1 = grid->ModifyLine(curr_line);
           final = LineOfSources(1, curr_line1);
        }
        }
        else{
            if (grid_y == 0 && slit_y != 0){
                LineOfSources curr_line = slit->ModifyLine(line);
                final = LineOfSources(1, curr_line);
            }
            if (grid_y != 0 && slit_y == 0){
                LineOfSources curr_line = grid->ModifyLine(line);
               final = LineOfSources(1, curr_line);
            }
            if (grid_y == 0 && slit_y == 0){
               final = LineOfSources(1, line);
            }
        }


    //LineOfSources curr_line = grid->ModifyLine(line);
  //LineOfSources curr_line1 = slit->ModifyLine(curr_line);
//    LineOfSources curr_line = grid->ModifyLine(line);
   // LineOfSources final = curr_line;
 //  LineOfSources final(1, curr_line1);
   // LineOfSources final = curr_line;

  //  final.Debug();
      std::cout << final.MaxAmpl() << std::endl;

    QVector<double> x(numberOfSources), y(numberOfSources);
    for (int i=0; i<numberOfSources; i++)
    {

      x[i] = final.Graph(i).first;
      y[i] = final.Graph(i).second * final.Graph(i).second;
    }
    // создаем график и добавляем данные:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
   // ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  //  ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
    // задаем имена осей координат
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // задаем размеры осей
    ui->widget->xAxis->setRange(min_x, max_x);
    ui->widget->yAxis->setRange(0, 1);
//     ui->widget->yAxis->setRange(0, 100000);
    ui->widget->replot();
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    QFile grid_data("./grid.txt");
    grid_data.open(QIODevice::WriteOnly | QIODevice::Text);
    QApplication::processEvents();

    QString g_data = ui->lineEdit->text();
    QTextStream out(&grid_data);
    out << g_data;
}


void MainWindow::on_lineEdit_returnPressed()
{


}


void MainWindow::on_lineEdit_editingFinished()
{

}

void MainWindow::on_lineEdit_2_returnPressed()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    QFile slit_data("./slit.txt");
    slit_data.open(QIODevice::WriteOnly | QIODevice::Text);
    QApplication::processEvents();

    QString s_data = ui->lineEdit_2->text();
    QTextStream out(&slit_data);
    out << s_data;
}
