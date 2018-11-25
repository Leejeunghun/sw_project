#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>
#include <iostream>
using namespace std;
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
   connect (this, SIGNAL(clicked()), this, SIGNAL(clicked()));
   string filePath = "test.txt";
       // write File
       ofstream writeFile(filePath.data());
       if( writeFile.is_open() ){
           writeFile << "Hello World!\n";
           writeFile << "This is C++ File Contents.\n";
           writeFile.close();
       }

       // read File
       ifstream openFile(filePath.data());
       if( openFile.is_open() ){
           string line;
           while(getline(openFile, line)){
               cout << line << endl;
           }
           openFile.close();
       }
}
