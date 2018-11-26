#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
int t=0;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_1_clicked()
{
    t=t+1;
    string filePath = "test.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<t<<endl;
            writeFile.close();
    }
   ui->lcdNumber->display(t);
}

void Dialog::on_pushButton_2_clicked()
{
    t=t-1;
    string filePath = "test.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<t<<endl;
            writeFile.close();
    }
   ui->lcdNumber->display(t);

}
