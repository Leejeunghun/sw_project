#include "dialog.h"
#include "ui_dialog.h"
#define MAX_SIZE 1000

char inputString[MAX_SIZE];
using namespace std;
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
void handlebutton(void)
{
    int t=0;
    ofstream outFile("output.txt");
         for(int i = 0 ; i < 10 ; i++){
                 outFile << i << endl;
         }
         outFile.close();
         t=t+1;
         ifstream inFile("output.txt");
         while(!inFile.eof()){
                 inFile.getline(inputString, 100);
                 cout << t << endl;
         }
         inFile.close();
    return ;
}


void Dialog::on_pushButton_clicked()
{
    connect(this,SIGNAL(on_pushButton_clicked()),this,SLOT(handlebutton));
    return ;
}




