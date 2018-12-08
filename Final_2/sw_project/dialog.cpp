#include "dialog.h"
#include "ui_dialog.h"
#include <stdlib.h>
#include <cstdlib>

int betting_1=1;
int betting_2=1;
int PLAYER_COIN_1=20;
int PLAYER_COIN_2=20;
int random_count=0;
int player_1_card[10]={};
int player_2_card[10]={};
int player =1;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    srand(time(NULL));
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
    if(player==1)
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
    else if (player ==2)
    {

        if(PLAYER_COIN_2 >betting_2)
        {
           betting_2=betting_2+1;
        }
        else
        {
            QMessageBox::information(this,"Error","NO COIN TO BET","OK");
            return;
        }
         ui->lcdNumber_bet->display(betting_2);
    }

}

void Dialog::on_pushButton_Down_clicked()
{
    if(player==1)
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
    if(player==2)
    {
     if(betting_2 >1)  //not using  //change
     {
        betting_2=betting_2-1;
     }
     else
     {
         QMessageBox::information(this,"Error","Do not betting 0","OK");
         return;
     }
    ui->lcdNumber_bet->display(betting_2);
    }
}


void Dialog::on_pushButton_commit_clicked()
{

    if(player==1)
    {
     string filePath = "nfsroot/betting_1.txt";
     // write File
         ofstream writeFile(filePath.data());
         if( writeFile.is_open() ){
             writeFile <<betting_1<<endl;
             writeFile.close();
          }
     PLAYER_COIN_1=PLAYER_COIN_1-betting_1;
      ui->lcdNumber_coin->display(PLAYER_COIN_1);
    }
    else if(player==2)
    {
        string filePath = "nfsroot/betting_2.txt";
        // write File
            ofstream writeFile(filePath.data());
            if( writeFile.is_open() ){
                writeFile <<betting_2<<endl;
                writeFile.close();
             }
        PLAYER_COIN_2=PLAYER_COIN_2-betting_2;
         ui->lcdNumber_coin->display(PLAYER_COIN_2);
    }
}

void Dialog::on_pushButton_Random_clicked()
{
    if(player=1)
    {
      if(random_count==10)
      {
          QMessageBox::information(this,"Game end","Game end","OK");
      }
      ui->lcdNumber_gamecount->display( random_count+1);
      //read file
      string filePath_1 = "nfsroot/oppent.txt";
      // write File
         ofstream writeFile(filePath_1.data());
      if( writeFile.is_open() ){
          writeFile <<player_1_card[random_count]<<endl;
          writeFile.close();
       }
      string filePath_2 = "nfsroot/oppent_2.txt";
          // write File
            ofstream writeFile_2(filePath_2.data());
            if( writeFile_2.is_open() ){
                writeFile_2 <<player_2_card[random_count]<<endl;
                writeFile_2.close();
          }
     ui->lcdNumber_random->display(player_1_card[random_count]);
   }

   if(player==2)
   {
        ui->lcdNumber_random->display(player_2_card[random_count]);
   }

   if(random_count<10)
   {
     random_count++;

   }
}

void Dialog::on_pushButton_Bet_clicked()
{
    int player1_bet=0;
    int player2_bet=0;
    string filePath_1 = "nfsroot/oppent_1.txt";
    ifstream openFile(filePath_1.data());
    if( openFile.is_open() ){
        string line;
        while(getline(openFile, line)){
        player1_bet=std::stoi(line );
        }
        openFile.close();
    }
\
    string filePath_2 = "nfsroot/oppent_2.txt";
    ifstream openFile_2(filePath_2.data());
    if( openFile_2.is_open() ){    ui->lcdNumber_coin->display(PLAYER_COIN_1);
        ui->lcdNumber_bet->display(betting_1);
        string line_2;
        while(getline(openFile_2, line_2)){
        player2_bet=std::stoi( line_2 );
        }
        openFile_2.close();
    }
    if(player1_bet<player2_bet)  //win
    {
         PLAYER_COIN_1 =PLAYER_COIN_1+(betting_1*2);
         PLAYER_COIN_2 =PLAYER_COIN_2;
         ui->lcdNumber_coin->display(PLAYER_COIN_1);
         ui->lcdNumber_bet->display(betting_1);
         QMessageBox::information(this,"GAME RESULT","WIN","OK");
    }
    else if(player1_bet>player2_bet)  //draw
    {
        PLAYER_COIN_1 =PLAYER_COIN_1;
        PLAYER_COIN_2 =PLAYER_COIN_2+(betting_1*2);
        ui->lcdNumber_coin->display(PLAYER_COIN_1);
        ui->lcdNumber_bet->display(betting_1);
       QMessageBox::information(this,"GAME RESULT","LOSE","OK");
    }
    else   //draw
    {
        PLAYER_COIN_1 =PLAYER_COIN_1+(betting_1);
        PLAYER_COIN_2 =PLAYER_COIN_2+(betting_1);
        ui->lcdNumber_coin->display(PLAYER_COIN_1);
        ui->lcdNumber_bet->display(betting_1);
       QMessageBox::information(this,"GAME RESULT","DRAW","OK");
    }

}

void Dialog::on_pushButton_player_clicked()
{

}

void Dialog::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1==0)
    {
        player=1;

    }
    else if(arg1!=0)
    {
        player=2;
   }
}

void Dialog::on_pushButton_clicked()
{
    int betting_1;
    int betting_2;
   if(player==1)
   {
       string filePath_1 = "nfsroot/betting_1.txt";
       ifstream openFile(filePath_1.data());
       if( openFile.is_open() ){
           string line;
           while(getline(openFile, line)){
           betting_1=std::stoi(line );
           }
           openFile.close();
       }
   }
   else if(player==2)
   {
       string filePath_2 = "nfsroot/betting_2.txt";
       ifstream openFile(filePath_2.data());
       if( openFile.is_open() ){
           string line;
           while(getline(openFile, line)){
           betting_2=std::stoi(line );
           }
           openFile.close();
       }
   }
}
