#include "dialog.h"
#include "ui_dialog.h"
#include <stdlib.h>
#include <cstdlib>
int betting_1=1;
int PLAYER_COIN_1=20;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lcdNumber_coin->display(PLAYER_COIN_1);
    ui->lcdNumber_bet->display(betting_1);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_Raise_clicked()
{
    if(PLAYER_COIN_1 >betting_1)
    {
       betting_1=betting_1+1;
    }
    else
    {
        QMessageBox::information(this,"Error","NO COIN TO BET","OK");
        return;
    }
   ui->lcdNumber_bet->display(betting_1);
}

void Dialog::on_pushButton_Down_clicked()
{
    if(betting_1 >1)  //not using  //change
    {
       betting_1=betting_1-1;
    }
    else
    {
        QMessageBox::information(this,"Error","Do not betting 0","OK");
        return;
    }
   ui->lcdNumber_bet->display(betting_1);
}

void Dialog::on_pushButton_commit_clicked()
{
    string filePath = "betting.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<betting_1<<endl;
            writeFile.close();
    }

}



void Dialog::on_pushButton_Random_clicked()
{
    int player_1_card=0;
    int player_2_card=0;
    player_1_card=rand()%10+1;
    player_2_card=rand()%10+1;
    //read file
    string filePath = "oppent.txt";
    // write File
        ofstream writeFile(filePath.data());
        if( writeFile.is_open() ){
            writeFile <<player_1_card<<endl;
            writeFile.close();
    }

    string filePath_2 = "oppent_2.txt";
        // write File
          ofstream writeFile_2(filePath.data());
          if( writeFile.is_open() ){
              writeFile <<player_2_card<<endl;
              writeFile.close();
      }
   ui->lcdNumber_random->display(player_1_card);
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
