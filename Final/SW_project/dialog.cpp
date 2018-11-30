#include "dialog.h"
#include "ui_dialog.h"
#include <stdlib.h>
#include <cstdlib>
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



void Dialog::on_pushButton_Random_clicked()
{
    int k=0;
    k=rand()%10+1;
    //read file
    string filePath = "oppent.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<k<<endl;
            writeFile.close();
    }
   ui->lcdNumber_random->display(k);
}



void Dialog::on_pushButton_Bet_clicked()
{
    int player1=0;
    int player2=0;
    string filePath = "oppent.txt";
    ifstream openFile(filePath.data());
    if( openFile.is_open() ){
        string line;
        while(getline(openFile, line)){
        player1=std::stoi(line );
        }
        openFile.close();
    }
\
    string filePath_2 = "oppent_2.txt";
    ifstream openFile_2(filePath_2.data());
    if( openFile.is_open() ){
        string line_2;
        while(getline(openFile, line_2)){
        player2=std::stoi( line_2 );
        }
        openFile.close();
    }



}
