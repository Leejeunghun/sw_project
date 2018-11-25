#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include<unistd.h>
#include <iostream>
#include <QFile>
#include <QTextStream>

#include <fstream>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void example();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
