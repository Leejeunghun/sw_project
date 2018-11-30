#include "dialog.h"
#include "ui_dialog.h"
int t=0;
int PLAYER_COIN_1=20;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lcdNumber_coin->display(PLAYER_COIN_1);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_Raise_clicked()
{
    if(PLAYER_COIN_1 >t)
    {
       t=t+1;
    }
    else
    {
        QMessageBox::information(this,"Error","NO COIN to BET","OK");
        return;
    }
   ui->lcdNumber_bet->display(t);
}

void Dialog::on_pushButton_Down_clicked()
{
    if(t >0)  //not using  //change
    {
       t=t-1;
    }
    else
    {
        QMessageBox::information(this,"Error","DO not betting minus","OK");
        return;
    }
   ui->lcdNumber_bet->display(t);
}

void Dialog::on_pushButton_commit_clicked()
{
    string filePath = "betting.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<t<<endl;
            writeFile.close();
    }

}

void Dialog::on_pushButton_Random()
{
    int k=0;
    k=rand()%10+1;
    string filePath = "oppent.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<k<<endl;
            writeFile.close();
    }
   ui->lcdNumber_random->display(k);

}
