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

  string filePath_1 = "nfsroot/total_1.txt";
  // write File
     ofstream writeFile_1(filePath_1.data());
  if( writeFile_1.is_open() ){
      writeFile_1 <<PLAYER_COIN_1<<endl;
      writeFile_1.close();
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
         QMessageBox::information(this,"Error","NO C(OIN TO BET","OK");
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
     { ui->lcdNumber_gamecount->display(random_count);
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
          } ui->lcdNumber_gamecount->display(random_count);
        ui->lcdNumber_bet->display(betting_1);
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
        ui->lcdNumber_bet->display(betting_2);
    }
}

void Dialog::on_pushButton_Random_clicked()
{
    if(player==1)
    {
      if(random_count==10)
      {
          QMessageBox::information(this,"Game end","Game end","OK");
      }
      string filePath_1 = "nfsroot/oppent_1.txt";
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
   }
   if(random_count<10)
   {
     random_count++;
     string filePath_3 = "nfsroot/game_count.txt";
         // write File
           ofstream writeFile_3(filePath_3.data());
           if( writeFile_3.is_open() ){
               writeFile_3 <<random_count<<endl;
               writeFile_3.close();
         }
   }
}
void Dialog::on_pushButton_Bet_clicked()
{
    int player1_card=0;
    int player2_card=0;ui->lcdNumber_gamecount->display(random_count);

    //read
    string filePath_1 = "nfsroot/oppent_1.txt";
    ifstream openFile(filePath_1.data());
    if( openFile.is_open() ){
        string line;
        while(getline(openFile, line)){
        player1_card=std::stoi(line );
        }
        openFile.close();
    }
\
    string filePath_2 = "nfsroot/oppent_2.txt"; ui->lcdNumber_gamecount->display(random_count);
    ifstream openFile_2(filePath_2.data());
    if( openFile_2.is_open() ){
        string line_2;
        while(getline(openFile_2, line_2)){
        player2_card=std::stoi( line_2 );
        }
        openFile_2.close();
    }
    if(player1_card>player2_card)  //win
    {
         PLAYER_COIN_1 =PLAYER_COIN_1+(betting_1);
         PLAYER_COIN_2 =PLAYER_COIN_2-(betting_1);
         QMessageBox::information(this,"GAME RESULT","WIN","OK");
    }
    else if(player1_card<player2_card)  //lose
    {
        PLAYER_COIN_1 =PLAYER_COIN_1-(betting_1);
        PLAYER_COIN_2 =PLAYER_COIN_2+(betting_1);
       QMessageBox::information(this,"GAME RESULT","LOSE","OK"); ui->lcdNumber_gamecount->display(random_count);
    }
    else   //draw
    {
        PLAYER_COIN_1 =PLAYER_COIN_1+(betting_1);
        PLAYER_COIN_2 =PLAYER_COIN_2+(betting_1);
       QMessageBox::information(this,"GAME RESULT","DRAW","OK");
    }

    string filePath_3 = "nfsroot/total_1.txt";
    // write File
       ofstream writeFile_1(filePath_3.data());
    if( writeFile_1.is_open() ){
        writeFile_1 <<PLAYER_COIN_1<<endl;
        writeFile_1.close();
     }

    string filePath_4 = "nfsroot/total_2.txt";
    // write File
       ofstream writeFile_2(filePath_4.data());
    if( writeFile_2.is_open() ){
        writeFile_2 <<PLAYER_COIN_2<<endl;
        writeFile_2.close();
     }

}



void Dialog::on_checkBox_2_stateChanged(int arg1)
{
    //player check
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
  int read_betting_1;
  int read_betting_2;
  int read_oppent_1;
  int read_oppent_2;
  int read_total_1;
  int read_total_2;
  int game_count;

       //read file
  string filePath_1 = "nfsroot/betting_1.txt";
  ifstream openFile_1(filePath_1.data());
  if( openFile_1.is_open() )
  {
    string line;
    while(getline(openFile_1, line))
    {
        read_betting_1=std::stoi(line );
    }
           openFile_1.close();
  }
  string filePath_2 = "nfsroot/betting_2.txt";
  ifstream openFile_2(filePath_2.data());
  if( openFile_2.is_open() )
  {
    string line;
    while(getline(openFile_2, line))
    {
        read_betting_2=std::stoi(line );
    }
           openFile_2.close();
  }

  string filePath_3 = "nfsroot/oppent_1.txt";
  ifstream openFile_3(filePath_3.data());
  if( openFile_3.is_open() )
  {
    string line;
    while(getline(openFile_3, line))
    {
        read_oppent_1=std::stoi(line );
    }
           openFile_3.close();
  }
  string filePath_4 = "nfsroot/oppent_2.txt";
  ifstream openFile_4(filePath_4.data());
  if( openFile_4.is_open() )
  {
    string line;
    while(getline(openFile_4, line))
    {
        read_oppent_2=std::stoi(line );
    }
           openFile_4.close();
  }

  string filePath_5 = "nfsroot/total_1.txt";
  ifstream openFile_5(filePath_5.data());
  if( openFile_5.is_open() )
  {
    string line;
    while(getline(openFile_5, line))
    {
        read_total_1=std::stoi(line );
    }
           openFile_5.close();
  }

  string filePath_6 = "nfsroot/total_2.txt";
  ifstream openFile_6(filePath_6.data());
  if( openFile_6.is_open() )
  {
    string line;
    while(getline(openFile_6, line))
    {
        read_total_2=std::stoi(line );
    }
           openFile_6.close();
    }
  string filePath_7 = "nfsroot/game_count.txt";
  ifstream openFile_7(filePath_7.data());
  if( openFile_7.is_open() )
  {
    string line;
    while(getline(openFile_7, line))
    {
        game_count=std::stoi(line );
    }
           openFile_7.close();
  }


  if(player==1)
  {
      ui->lcdNumber_player->display(read_betting_2);
      ui->lcdNumber_random->display(read_oppent_2);
      ui->lcdNumber_coin->display(read_total_1);
  }

  if(player==2)
  {
      ui->lcdNumber_player->display(read_betting_1);
      ui->lcdNumber_random->display(read_oppent_1);
      ui->lcdNumber_coin->display(read_total_2);
  }
  ui->lcdNumber_gamecount->display(random_count);


}

void Dialog::on_pushButton_2_clicked()
{
    int read_betting_1;
    int read_betting_2;
    string filePath_1 = "nfsroot/betting_1.txt";
    ifstream openFile_1(filePath_1.data());
    if( openFile_1.is_open() )
    {
      string line;
      while(getline(openFile_1, line))
      {
          read_betting_1=std::stoi(line );
      }
             openFile_1.close();
    }

     string filePath_2 = "nfsroot/betting_2.txt";
    ifstream openFile_2(filePath_2.data());
    if( openFile_2.is_open() )
    {
      string line;
      while(getline(openFile_2, line))
      {
          read_betting_2=std::stoi(line );
      }
             openFile_2.close();
    }

   if(player==1)  //push die
    {
         PLAYER_COIN_1 =PLAYER_COIN_1-(read_betting_2);
         PLAYER_COIN_2 =PLAYER_COIN_2+(read_betting_2);
    }
    else if(player==2)  //push die
    {
        PLAYER_COIN_1 =PLAYER_COIN_1+(read_betting_1);
        PLAYER_COIN_2 =PLAYER_COIN_2-(read_betting_1);
    }
    QMessageBox::information(this,"GAME RESULT","you betting give up","OK");
    string filePath_3 = "nfsroot/total_1.txt";
    // write File
       ofstream writeFile_1(filePath_3.data());
    if( writeFile_1.is_open() ){
        writeFile_1 <<PLAYER_COIN_1<<endl;
        writeFile_1.close();
     }

    string filePath_4 = "nfsroot/total_2.txt";
    // write File
       ofstream writeFile_2(filePath_4.data());
    if( writeFile_2.is_open() ){
        writeFile_2 <<PLAYER_COIN_2<<endl;
        writeFile_2.close();
     }
}
