#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDialog>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include<unistd.h>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <cstdlib>
#include <QMessageBox>
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

    void on_pushButton_Random();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
