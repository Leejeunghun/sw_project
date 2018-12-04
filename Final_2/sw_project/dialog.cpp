#include "dialog.h"
#include "ui_dialog.h"
#include <stdlib.h>
#include <cstdlib>

int betting_1=1;
int PLAYER_COIN_1=20;
int PLAYER_COIN_2=20;
int random_count=0;
int player_1_card[10]={};
int player_2_card[10]={};
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    srand(10);
    ui->setupUi(this);
    ui->lcdNumber_coin->display(PLAYER_COIN_1);
    ui->lcdNumber_bet->display(betting_1);
// random array

    for(int i=1;i<10;i++)
   {
      player_1_card[i]=i;
   }
   for(int i=0;i<50;i++)
   {
     int s1=rand()%10;
     int s2=rand()%10;

     int temp=player_1_card[s1];
     player_1_card[s1]=player_1_card[s2];
     player_1_card[s2]=temp;

   }


  for(int i=1;i<10;i++)
  {
     player_2_card[i]=i;
  }
  for(int i=0;i<50;i++)
  {
    int s1=rand()%10;
    int s2=rand()%10;

    int temp=player_2_card[s1];
    player_2_card[s1]=player_2_card[s2];
    player_2_card[s2]=temp;

  }
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
    PLAYER_COIN_1=PLAYER_COIN_1-betting_1;
     ui->lcdNumber_coin->display(PLAYER_COIN_1);
}

void Dialog::on_pushButton_Random_clicked()
{
    if(random_count==10)
    {
        QMessageBox::information(this,"Game end","Game end","OK");
    }
    ui->lcdNumber_gamecount->display( random_count+1);
    //read file
    string filePath_1 = "oppent.txt";
    // write File
       ofstream writeFile(filePath_1.data());
    if( writeFile.is_open() ){
        writeFile <<player_1_card[random_count]<<endl;
        writeFile.close();
     }
    string filePath_2 = "oppent_2.txt";
        // write File
          ofstream writeFile_2(filePath_2.data());
          if( writeFile_2.is_open() ){
              writeFile_2 <<player_2_card[random_count]<<endl;
              writeFile_2.close();
      }
   ui->lcdNumber->display(player_2_card[random_count]);
   ui->lcdNumber_random->display(player_1_card[random_count]);
   if(random_count<10)
   {
     random_count++;

   }
}

void Dialog::on_pushButton_Bet_clicked()
{
    int player1=0;
    int player2=0;
    string filePath_1 = "oppent.txt";
    ifstream openFile(filePath_1.data());
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
    if( openFile_2.is_open() ){    ui->lcdNumber_coin->display(PLAYER_COIN_1);
        ui->lcdNumber_bet->display(betting_1);
        string line_2;
        while(getline(openFile_2, line_2)){
        player2=std::stoi( line_2 );
        }
        openFile_2.close();
    }
    if(player1<player2)
    {
         PLAYER_COIN_1 =PLAYER_COIN_1+(betting_1*2);
         PLAYER_COIN_2 =PLAYER_COIN_2;
         ui->lcdNumber_coin->display(PLAYER_COIN_1);
         ui->lcdNumber_bet->display(betting_1);
         QMessageBox::information(this,"GAME RESULT","WIN","OK");
    }
    else if(player1>player2)
    {
        PLAYER_COIN_1 =PLAYER_COIN_1;
        PLAYER_COIN_2 =PLAYER_COIN_2+(betting_1*2);
        ui->lcdNumber_coin->display(PLAYER_COIN_1);
        ui->lcdNumber_bet->display(betting_1);
       QMessageBox::information(this,"GAME RESULT","LOSE","OK");
    }
    else
    {
        PLAYER_COIN_1 =PLAYER_COIN_1+(betting_1);
        PLAYER_COIN_2 =PLAYER_COIN_2+(betting_1);
        ui->lcdNumber_coin->display(PLAYER_COIN_1);
        ui->lcdNumber_bet->display(betting_1);
       QMessageBox::information(this,"GAME RESULT","DRAW","OK");
    }

}
