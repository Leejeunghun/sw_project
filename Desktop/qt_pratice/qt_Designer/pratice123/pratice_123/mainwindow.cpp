#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
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
