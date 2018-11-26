#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <iostream>
using namespace std;
int t=0;
Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::example() {
}

void Dialog::on_pushButton_clicked()
{
     t=t+1;
     string filePath = "test.txt";
     // read File
     ifstream openFile(filePath.data());
     if( openFile.is_open() ){
         string line;
         while(getline(openFile, line)){
             cout << line << endl;
         }
         openFile.close();
     }
     // write File
         ofstream writeFile(filePath.data());
         if( writeFile.is_open() ){
             writeFile <<t<<endl;
             writeFile.close();
     }

}
