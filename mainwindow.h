#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

namespace Ui {
class MainWindow; 
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_textEdit_copyAvailable(bool b);

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_editingFinished();



    void on_lineEdit_2_returnPressed();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
