#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <unistd.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <fstream>

#include <QMessageBox>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_Raise_clicked();

    void on_pushButton_Down_clicked();

    void on_pushButton_commit_clicked();

    void on_pushButton_Random_clicked();

    void on_pushButton_Bet_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
