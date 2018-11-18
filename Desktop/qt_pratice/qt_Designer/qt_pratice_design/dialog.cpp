#include "dialog.h"
#include "ui_dialog.h"

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

void Dialog::on_pushButton_clicked()
{
    int t=0;
    {
        QString filename = "Data.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite))
        {
             QTextStream stream(&file);
             stream << t << endl;
             stream.flush();
        }
    }
}


void Dialog::on_spinBox_editingFinished()
{

}

void Dialog::on_textEdit_2_textChanged()
{


}


